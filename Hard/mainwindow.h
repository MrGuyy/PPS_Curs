#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtWidgets>
#include <QtConcurrent/QtConcurrent>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_load_button_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_save_button_clicked();
    void channel_changed();

    void on_save_button_2_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap fromImage(const QImage qImg);
    QImage original_unscalled_image;
    QImage current_gamma_image;
    QVector <int> mode_filtering_order;
    QVector <double> gamma_filtering_order;
    int filtering_order_size = 0;
    bool red_channel_flag = true;
    bool green_channel_flag = true;
    bool blue_channel_flag = true;
    enum channelMode { BLUE = 1, GREEN = 2, GREEN_BLUE = 3, RED = 4, RED_BLUE = 5, RED_GREEN = 6, RGB = 7 };
    channelMode mode = RGB;
    channelMode savemode = RGB;
    QImage gamma(const QImage &qImg, double exp, channelMode mode);
    void build_gamma_graphic(const QImage qImg);
};
#endif // MAINWINDOW_H
