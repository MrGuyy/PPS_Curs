/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *image_text;
    QLabel *original_image;
    QVBoxLayout *verticalLayout_2;
    QLabel *gamma_text;
    QLabel *gamma_image;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QCheckBox *redChannel;
    QCheckBox *greenChannel;
    QCheckBox *blueChannel;
    QPushButton *save_button_2;
    QVBoxLayout *verticalLayout_6;
    QPushButton *load_button;
    QPushButton *save_button;
    QCustomPlot *widget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *gamma_number;
    QSlider *horizontalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 710);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        image_text = new QLabel(centralwidget);
        image_text->setObjectName(QString::fromUtf8("image_text"));
        image_text->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(image_text);

        original_image = new QLabel(centralwidget);
        original_image->setObjectName(QString::fromUtf8("original_image"));
        original_image->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/cat2.png")));
        original_image->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(original_image);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gamma_text = new QLabel(centralwidget);
        gamma_text->setObjectName(QString::fromUtf8("gamma_text"));
        gamma_text->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(gamma_text);

        gamma_image = new QLabel(centralwidget);
        gamma_image->setObjectName(QString::fromUtf8("gamma_image"));
        gamma_image->setEnabled(true);
        gamma_image->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/cat2.png")));
        gamma_image->setScaledContents(false);
        gamma_image->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(gamma_image);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_5->addWidget(label_2);

        redChannel = new QCheckBox(frame);
        redChannel->setObjectName(QString::fromUtf8("redChannel"));
        redChannel->setChecked(true);

        verticalLayout_5->addWidget(redChannel);

        greenChannel = new QCheckBox(frame);
        greenChannel->setObjectName(QString::fromUtf8("greenChannel"));
        greenChannel->setChecked(true);

        verticalLayout_5->addWidget(greenChannel);

        blueChannel = new QCheckBox(frame);
        blueChannel->setObjectName(QString::fromUtf8("blueChannel"));
        blueChannel->setChecked(true);

        verticalLayout_5->addWidget(blueChannel);

        save_button_2 = new QPushButton(frame);
        save_button_2->setObjectName(QString::fromUtf8("save_button_2"));
        save_button_2->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_5->addWidget(save_button_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        load_button = new QPushButton(frame);
        load_button->setObjectName(QString::fromUtf8("load_button"));
        load_button->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_6->addWidget(load_button);

        save_button = new QPushButton(frame);
        save_button->setObjectName(QString::fromUtf8("save_button"));
        save_button->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_6->addWidget(save_button);


        verticalLayout_5->addLayout(verticalLayout_6);


        horizontalLayout_4->addLayout(verticalLayout_5);

        widget = new QCustomPlot(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(401, 181));

        horizontalLayout_4->addWidget(widget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        gamma_number = new QLabel(frame);
        gamma_number->setObjectName(QString::fromUtf8("gamma_number"));

        horizontalLayout_3->addWidget(gamma_number);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalSlider = new QSlider(frame);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(50);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(10);
        horizontalSlider->setValue(10);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::NoTicks);

        verticalLayout_4->addWidget(horizontalSlider);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_3->addWidget(frame);


        horizontalLayout_2->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\223\320\260\320\274\320\274\320\260 \320\272\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217", nullptr));
        image_text->setText(QCoreApplication::translate("MainWindow", "\320\236\321\200\320\270\320\263\320\270\320\275\320\260\320\273\321\214\320\275\320\276\320\265 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        original_image->setText(QString());
        gamma_text->setText(QCoreApplication::translate("MainWindow", "\320\223\320\260\320\274\320\274\320\260 \320\272\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217", nullptr));
        gamma_image->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273\321\213:", nullptr));
        redChannel->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        greenChannel->setText(QCoreApplication::translate("MainWindow", "Green", nullptr));
        blueChannel->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        save_button_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        load_button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        save_button->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\223\320\260\320\274\320\274\320\260 \320\272\320\276\321\215\321\204\320\270\321\206\320\270\320\265\320\275\321\202:", nullptr));
        gamma_number->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
