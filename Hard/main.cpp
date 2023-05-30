#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>

//QPixmap fromImage(const QImage &qImg)
//{
//QPixmap qPixmap;
//qPixmap.convertFromImage(qImg);
//return qPixmap;
//}

//QImage gamma(const QImage &qImg, double exp)
//{
//QImage qImgRet(qImg);
//for (int x = 0; x < qImg.width(); ++x) {
//for (int y = 0 ; y < qImg.height(); ++y) {
//const QRgb rgb = qImg.pixel(x, y);
//const double r = qRed(rgb) / 255.0;
//const double g = qGreen(rgb) / 255.0;
//const double b = qBlue(rgb) / 255.0;
//qImgRet.setPixelColor(x, y,
//QColor(
//255 * std::pow(r, exp),
//255 * std::pow(g, exp),
//255 * std::pow(b, exp)));
//}
//}
//return qImgRet;
//}

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    srand(time(NULL));
    QImageReader::setAllocationLimit(0);
    MainWindow w;
    w.show();
    return a.exec();
}

//qDebug() << "Qt Version:" << QT_VERSION_STR;
//QApplication app(argc, argv);
//// setup data
//QImage qImg("C:/Users/Nikita/Documents/Hard/cat.png");
//QImage qTempImg = qImg.scaled(640,480,Qt::KeepAspectRatio);
//const QImage qImgGamma = gamma(qTempImg, 1 / 0.3);
//// setup UI
//QWidget qWin;
//qWin.setWindowTitle(QString::fromUtf8("Gamma Correction"));
//QVBoxLayout qVBox;
//QLabel qLbl(QString::fromUtf8("Original Image:"));
//qVBox.addWidget(&qLbl);
//QLabel qLblImg;
//qLblImg.setPixmap(fromImage(qTempImg));
//qVBox.addWidget(&qLblImg);
//qWin.setLayout(&qVBox);
//QLabel qLblGamma(QString::fromUtf8("Gamma corrected Image:"));
//qVBox.addWidget(&qLblGamma);
//QLabel qLblImgGamma;
//qLblImgGamma.setPixmap(fromImage(qImgGamma));
//qVBox.addWidget(&qLblImgGamma);
//qWin.setLayout(&qVBox);
//qWin.show();
//// runtime loop
//return app.exec();
