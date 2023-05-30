#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->xAxis->setRange(0,265);
    ui->widget->yAxis->setRange(0,2);
    ui->widget->yAxis->setLabel("*10^4");
    ui->widget->plotLayout()->insertRow(0);
    ui->widget->plotLayout()->addElement(0, 0, new QCPTextElement(ui->widget, "Гистограмма изображения", QFont("sans", 12, QFont::Bold)));
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    connect(ui->redChannel,SIGNAL(clicked()),this,SLOT(channel_changed()));
    connect(ui->greenChannel,SIGNAL(clicked()),this,SLOT(channel_changed()));
    connect(ui->blueChannel,SIGNAL(clicked()),this,SLOT(channel_changed()));
    current_gamma_image = ui->original_image->pixmap().toImage();
    original_unscalled_image = ui->original_image->pixmap().toImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_load_button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Выберите изображение"), "", tr("Файл изображения (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty()) {
        ui->load_button->setEnabled(false);
        ui->horizontalSlider->setEnabled(false);
        ui->save_button->setEnabled(false);
        ui->save_button_2->setEnabled(false);
        ui->redChannel->setEnabled(false);
        ui->greenChannel->setEnabled(false);
        ui->blueChannel->setEnabled(false);
        gamma_filtering_order.clear();
        mode_filtering_order.clear();
        filtering_order_size = 0;
        savemode = RGB;
        QFutureWatcher<bool> watcher;
        QFuture<bool> future = QtConcurrent::run([&](){
            QImage qTempImg(fileName);
            original_unscalled_image.load(fileName);
            if (qTempImg.width()>566 || qTempImg.height()>400)
                qTempImg = qTempImg.scaled(566,400,Qt::KeepAspectRatio);
            ui->original_image->setPixmap(fromImage(qTempImg));
            ui->gamma_image->setPixmap(fromImage(qTempImg));
            return true;
        });
        QEventLoop loop;
        connect(&watcher, &QFutureWatcherBase::finished, &loop, &QEventLoop::quit);
        watcher.setFuture(future);
        loop.exec();
        current_gamma_image = ui->original_image->pixmap().toImage();
        ui->load_button->setEnabled(watcher.result());
        ui->horizontalSlider->setEnabled(watcher.result());
        ui->save_button->setEnabled(watcher.result());
        ui->horizontalSlider->setValue(10);
        ui->save_button_2->setEnabled(watcher.result());
        ui->redChannel->setEnabled(watcher.result());
        ui->greenChannel->setEnabled(watcher.result());
        ui->blueChannel->setEnabled(watcher.result());

//        QImage qTempImg(fileName);
//        qTempImg = qTempImg.scaled(640,480,Qt::KeepAspectRatio);
//        ui->original_image->setPixmap(fromImage(qTempImg));
//        ui->gamma_image->setPixmap(fromImage(qTempImg));
    }
}

QPixmap MainWindow::fromImage(const QImage qImg)
{
    QPixmap qPixmap;
    qPixmap.convertFromImage(qImg);
    return qPixmap;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    double gamma_num = value/10.0;
    ui->gamma_number->setText(QString::number(gamma_num));
    QImage qImgTemp = current_gamma_image;
    qImgTemp = gamma(qImgTemp, gamma_num,mode);
    build_gamma_graphic(qImgTemp);
    ui->gamma_image->setPixmap(fromImage(qImgTemp));
}

QImage MainWindow::gamma(const QImage &qImg, double exp, channelMode mode)
{
QImage qImgRet(qImg);
switch(mode) {
case BLUE:
    for (int x = 0; x < qImg.width(); ++x) {
    for (int y = 0 ; y < qImg.height(); ++y) {
    const QRgb rgb = qImg.pixel(x, y);
    const double b = qBlue(rgb) / 255.0;
    qImgRet.setPixelColor(x, y,
    QColor(
    qRed(rgb),
    qGreen(rgb),
    255 * std::pow(b, exp)));
    }
    }
    break;
case GREEN:
    for (int x = 0; x < qImg.width(); ++x) {
    for (int y = 0 ; y < qImg.height(); ++y) {
    const QRgb rgb = qImg.pixel(x, y);
    const double g = qGreen(rgb) / 255.0;
    qImgRet.setPixelColor(x, y,
    QColor(
    qRed(rgb),
    255 * std::pow(g, exp),
    qBlue(rgb)));
    }
    }
    break;
case GREEN_BLUE:
    for (int x = 0; x < qImg.width(); ++x) {
    for (int y = 0 ; y < qImg.height(); ++y) {
    const QRgb rgb = qImg.pixel(x, y);
    const double g = qGreen(rgb) / 255.0;
    const double b = qBlue(rgb) / 255.0;
    qImgRet.setPixelColor(x, y,
    QColor(
    qRed(rgb),
    255 * std::pow(g, exp),
    255 * std::pow(b, exp)));
    }
    }
    break;
case RED:
    for (int x = 0; x < qImg.width(); ++x) {
    for (int y = 0 ; y < qImg.height(); ++y) {
    const QRgb rgb = qImg.pixel(x, y);
    const double r = qRed(rgb) / 255.0;
    qImgRet.setPixelColor(x, y,
    QColor(
    255 * std::pow(r, exp),
    qGreen(rgb),
    qBlue(rgb)));
    }
    }
    break;
case RED_BLUE:
    for (int x = 0; x < qImg.width(); ++x) {
    for (int y = 0 ; y < qImg.height(); ++y) {
    const QRgb rgb = qImg.pixel(x, y);
    const double r = qRed(rgb) / 255.0;
    const double b = qBlue(rgb) / 255.0;
    qImgRet.setPixelColor(x, y,
    QColor(
    255 * std::pow(r, exp),
    qGreen(rgb),
    255 * std::pow(b, exp)));
    }
    }
    break;
case RED_GREEN:
    for (int x = 0; x < qImg.width(); ++x) {
    for (int y = 0 ; y < qImg.height(); ++y) {
    const QRgb rgb = qImg.pixel(x, y);
    const double r = qRed(rgb) / 255.0;
    const double g = qGreen(rgb) / 255.0;
    qImgRet.setPixelColor(x, y,
    QColor(
    255 * std::pow(r, exp),
    255 * std::pow(g, exp),
    qBlue(rgb)));
    }
    }
    break;
case RGB:
    for (int x = 0; x < qImg.width(); ++x) {
    for (int y = 0 ; y < qImg.height(); ++y) {
    const QRgb rgb = qImg.pixel(x, y);
    const double r = qRed(rgb) / 255.0;
    const double g = qGreen(rgb) / 255.0;
    const double b = qBlue(rgb) / 255.0;
    qImgRet.setPixelColor(x, y,
    QColor(
    255 * std::pow(r, exp),
    255 * std::pow(g, exp),
    255 * std::pow(b, exp)));
    }
    }
    break;
}


return qImgRet;
}

void MainWindow::build_gamma_graphic(const QImage qImg)
{
    QVector <double> red_count, blue_count, green_count, xAxis;
    red_count.resize(256);
    blue_count.resize(256);
    green_count.resize(256);
    for (int i = 0; i < red_count.size(); i++) {
        xAxis.push_back(i);
    }
    for (int x = 0; x < qImg.width(); ++x) {
    for (int y = 0 ; y < qImg.height(); ++y) {
    const QRgb rgb = qImg.pixel(x, y);
    red_count[qRed(rgb)]++;
    green_count[qGreen(rgb)]++;
    blue_count[qBlue(rgb)]++;
    }
    }
    for (int i = 0; i < red_count.size(); i++) {
         red_count[i]=red_count[i]/10000;
         blue_count[i]=blue_count[i]/10000;
         green_count[i]=green_count[i]/10000;
    }
    ui->widget->addGraph(ui->widget->xAxis, ui->widget->yAxis);
    ui->widget->graph(0)->setPen(QPen(Qt::red));
    ui->widget->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 20)));
    ui->widget->addGraph();
    ui->widget->graph(1)->setPen(QPen(Qt::green));
    ui->widget->graph(1)->setBrush(QBrush(QColor(0, 255, 0, 20)));
    ui->widget->addGraph();
    ui->widget->graph(2)->setPen(QPen(Qt::blue));
    ui->widget->graph(2)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget->graph(0)->setData(xAxis,red_count);
    ui->widget->graph(1)->setData(xAxis,green_count);
    ui->widget->graph(2)->setData(xAxis,blue_count);
    ui->widget->replot();
}


void MainWindow::on_save_button_clicked()
{
    if (gamma_filtering_order.isEmpty() && !qFuzzyCompare((ui->horizontalSlider->value()/10.0),1.0)) {
        mode_filtering_order.push_back(mode);
        gamma_filtering_order.push_back((ui->horizontalSlider->value()/10.0));
        filtering_order_size++;
    }
    else if (filtering_order_size != 0) {
        if (!qFuzzyCompare(gamma_filtering_order[filtering_order_size-1],(ui->horizontalSlider->value()/10.0))) {
            mode_filtering_order.push_back(mode);
            gamma_filtering_order.push_back((ui->horizontalSlider->value()/10.0));
            filtering_order_size++;
        }
    }
    ui->load_button->setEnabled(false);
    ui->horizontalSlider->setEnabled(false);
    ui->save_button->setEnabled(false);
    ui->save_button_2->setEnabled(false);
    ui->redChannel->setEnabled(false);
    ui->greenChannel->setEnabled(false);
    ui->blueChannel->setEnabled(false);
    QString fileName;
    QImage qImgTemp = original_unscalled_image;
    QFutureWatcher<bool> watcher;
    QFuture<bool> future = QtConcurrent::run([&](){
        for (int i = 0; i < gamma_filtering_order.size(); i++) {
            switch (mode_filtering_order[i]) {
            case 1:
                savemode = BLUE;
                break;
            case 2:
                savemode = GREEN;
                break;
            case 3:
                savemode = GREEN_BLUE;
                break;
            case 4:
                savemode = RED;
                break;
            case 5:
                savemode = RED_BLUE;
                break;
            case 6:
                savemode = RED_GREEN;
                break;
            case 7:
                savemode = RGB;
                break;
            }

            qImgTemp = gamma(qImgTemp, gamma_filtering_order[i],savemode);
        }
    return true;
    });
    QEventLoop loop;
    connect(&watcher, &QFutureWatcherBase::finished, &loop, &QEventLoop::quit);
    watcher.setFuture(future);
    loop.exec();
    fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/home/jana/untitled.png",
                               tr("Images (*.png *.xpm *.jpg)"));
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    qImgTemp.save(&file);
    file.close();
    ui->load_button->setEnabled(true);
    ui->horizontalSlider->setEnabled(true);
    ui->save_button->setEnabled(true);
    ui->save_button_2->setEnabled(true);
    ui->redChannel->setEnabled(true);
    ui->greenChannel->setEnabled(true);
    ui->blueChannel->setEnabled(true);
}

void MainWindow::channel_changed()
{
    current_gamma_image = ui->gamma_image->pixmap().toImage();
    if (gamma_filtering_order.isEmpty() && !qFuzzyCompare((ui->horizontalSlider->value()/10.0),1.0)) {
        mode_filtering_order.push_back(mode);
        gamma_filtering_order.push_back((ui->horizontalSlider->value()/10.0));
        filtering_order_size++;
    }
    else if (filtering_order_size != 0) {
        if (!qFuzzyCompare(gamma_filtering_order[filtering_order_size-1],(ui->horizontalSlider->value()/10.0))) {
            mode_filtering_order.push_back(mode);
            gamma_filtering_order.push_back((ui->horizontalSlider->value()/10.0));
            filtering_order_size++;
        }
    }
    red_channel_flag = ui->redChannel->isChecked();
    green_channel_flag = ui->greenChannel->isChecked();
    blue_channel_flag = ui->blueChannel->isChecked();
    ui->horizontalSlider->setValue(10);
    if (!red_channel_flag && !green_channel_flag && !blue_channel_flag) {
        ui->horizontalSlider->setEnabled(false);
    }
    else {
        ui->horizontalSlider->setEnabled(true);
    }
    if (red_channel_flag == true && green_channel_flag == false && blue_channel_flag == false) {
        mode = RED;
    }
    else if (red_channel_flag == true && green_channel_flag == true && blue_channel_flag == false) {
        mode = RED_GREEN;
    }
    else if (red_channel_flag == false && green_channel_flag == true && blue_channel_flag == false) {
        mode = GREEN;
    }
    else if (red_channel_flag == false && green_channel_flag == true && blue_channel_flag == true) {
        mode = GREEN_BLUE;
    }
    else if (red_channel_flag == false && green_channel_flag == false && blue_channel_flag == true) {
        mode = BLUE;
    }
    else if (red_channel_flag == true && green_channel_flag == false && blue_channel_flag == true) {
        mode = RED_BLUE;
    }
    else if (red_channel_flag == true && green_channel_flag == true && blue_channel_flag == true) {
        mode = RGB;
    }
}


void MainWindow::on_save_button_2_clicked()
{
     ui->horizontalSlider->setValue(10);
     ui->gamma_image->setPixmap(ui->original_image->pixmap());
     gamma_filtering_order.clear();
     mode_filtering_order.clear();
     filtering_order_size = 0;
     savemode = RGB;
     current_gamma_image = ui->gamma_image->pixmap().toImage();
     build_gamma_graphic(ui->original_image->pixmap().toImage());
}

