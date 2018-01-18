/********************************************************************************
** Form generated from reading UI file 'VideoPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYER_H
#define UI_VIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "videoopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_VideoPlayerClass
{
public:
    QWidget *centralWidget;
    VideoOpenGLWidget *vowScreen;
    QWidget *bottomWidget;
    QPushButton *pushButton;
    QPushButton *pauseButton;
    QPushButton *playButton;
    QSlider *playSlider;
    QWidget *topButtons;
    QPushButton *minButton;
    QPushButton *maxButton;
    QPushButton *closeButton;

    void setupUi(QMainWindow *VideoPlayerClass)
    {
        if (VideoPlayerClass->objectName().isEmpty())
            VideoPlayerClass->setObjectName(QStringLiteral("VideoPlayerClass"));
        VideoPlayerClass->resize(852, 515);
        VideoPlayerClass->setStyleSheet(QString::fromUtf8("#VideoPlayerClass{\n"
"background-color: rgb(0, 0, 0);\n"
"}\n"
"QPushButton:!hover\n"
"{\n"
"    background-color: qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 rgba(120, 120, 120, 255),stop:0.495      rgba(39, 39, 39, 255),stop:0.505 rgba(39, 39, 39, 255),stop:1 rgba(120, 120, 120, 255));\n"
"    border:none;\n"
"    border-radius:5px;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 75 12pt \"\351\273\221\344\275\223\";\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"    background-color: qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 rgba(39, 39, 39, 255),stop:0.495      rgba(120, 120, 120, 255),stop:0.505 rgba(120, 120, 120, 255),stop:1 rgba(39, 39, 39, 255));\n"
"    border:none;\n"
"    border-radius:5px;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 75 12pt \"\351\273\221\344\275\223\";\n"
"}\n"
"#centralWidget{\n"
"background-color: rgb(0, 0, 0);\n"
"}\n"
"#closeButton,#maxButton,#minButton\n"
"{\n"
"font: 75 11pt \"\347\255\211\347\272\277\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0,"
                        " 0);\n"
"}\n"
"\n"
"#playButton{background-color: rgba(255, 255, 255,0);}\n"
"\n"
"#playButton:hover{image: url(:/VideoPlayer/Resources/PlayN.png);}\n"
"\n"
"#playButton:!hover{image: url(:/VideoPlayer/Resources/PlayH.png);}\n"
"\n"
"#playButton:pressed{image: url(:/VideoPlayer/Resources/PlayP.png);}\n"
"\n"
"#pauseButton{background-color: rgba(255, 255, 255,0);}\n"
"\n"
"#pauseButton:hover{image: url(:/VideoPlayer/Resources/PauseN.png);}\n"
"\n"
"#pauseButton:!hover{image: url(:/VideoPlayer/Resources/PauseH.png);}\n"
"\n"
"#pauseButton:pressed{image: url(:/VideoPlayer/Resources/PauseP.png);}\n"
""));
        centralWidget = new QWidget(VideoPlayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        vowScreen = new VideoOpenGLWidget(centralWidget);
        vowScreen->setObjectName(QStringLiteral("vowScreen"));
        vowScreen->setGeometry(QRect(0, 0, 852, 520));
        bottomWidget = new QWidget(centralWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        bottomWidget->setGeometry(QRect(0, 430, 851, 80));
        bottomWidget->setStyleSheet(QLatin1String(" \n"
"background-color: rgba(0, 0, 0, 122);"));
        pushButton = new QPushButton(bottomWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 40, 93, 28));
        pauseButton = new QPushButton(bottomWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setGeometry(QRect(450, 40, 31, 28));
        playButton = new QPushButton(bottomWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(490, 40, 31, 28));
        playSlider = new QSlider(bottomWidget);
        playSlider->setObjectName(QStringLiteral("playSlider"));
        playSlider->setGeometry(QRect(120, 10, 601, 22));
        playSlider->setMaximum(999);
        playSlider->setOrientation(Qt::Horizontal);
        topButtons = new QWidget(centralWidget);
        topButtons->setObjectName(QStringLiteral("topButtons"));
        topButtons->setGeometry(QRect(770, 10, 71, 21));
        minButton = new QPushButton(topButtons);
        minButton->setObjectName(QStringLiteral("minButton"));
        minButton->setGeometry(QRect(0, 0, 18, 19));
        maxButton = new QPushButton(topButtons);
        maxButton->setObjectName(QStringLiteral("maxButton"));
        maxButton->setGeometry(QRect(20, 0, 27, 19));
        closeButton = new QPushButton(topButtons);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(50, 0, 21, 20));
        VideoPlayerClass->setCentralWidget(centralWidget);

        retranslateUi(VideoPlayerClass);
        QObject::connect(pushButton, SIGNAL(clicked()), VideoPlayerClass, SLOT(openVideo()));
        QObject::connect(pauseButton, SIGNAL(clicked()), VideoPlayerClass, SLOT(pause()));
        QObject::connect(playButton, SIGNAL(clicked()), VideoPlayerClass, SLOT(play()));
        QObject::connect(playSlider, SIGNAL(sliderMoved(int)), VideoPlayerClass, SLOT(setPos(int)));
        QObject::connect(playSlider, SIGNAL(sliderPressed()), VideoPlayerClass, SLOT(sliderPress()));
        QObject::connect(playSlider, SIGNAL(sliderReleased()), VideoPlayerClass, SLOT(sliderRelease()));
        QObject::connect(closeButton, SIGNAL(clicked()), VideoPlayerClass, SLOT(close()));
        QObject::connect(minButton, SIGNAL(clicked()), VideoPlayerClass, SLOT(showMinimized()));
        QObject::connect(maxButton, SIGNAL(clicked()), VideoPlayerClass, SLOT(fullResetScreen()));

        QMetaObject::connectSlotsByName(VideoPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *VideoPlayerClass)
    {
        VideoPlayerClass->setWindowTitle(QApplication::translate("VideoPlayerClass", "VideoPlayer", Q_NULLPTR));
        pushButton->setText(QApplication::translate("VideoPlayerClass", "open", Q_NULLPTR));
        pauseButton->setText(QString());
        playButton->setText(QString());
        minButton->setText(QApplication::translate("VideoPlayerClass", "\344\270\200", Q_NULLPTR));
        maxButton->setText(QApplication::translate("VideoPlayerClass", "\345\217\243", Q_NULLPTR));
        closeButton->setText(QApplication::translate("VideoPlayerClass", "X", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VideoPlayerClass: public Ui_VideoPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYER_H
