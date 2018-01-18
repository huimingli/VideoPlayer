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
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *pushButton;
    QPushButton *pauseButton;
    QPushButton *playButton;
    QSlider *playSlider;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *minButton;
    QPushButton *maxButton;
    QPushButton *closeButton;
    VideoOpenGLWidget *vowScreen;

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
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(500, 470, 93, 28));
        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setGeometry(QRect(360, 470, 31, 28));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(400, 470, 31, 28));
        playSlider = new QSlider(centralWidget);
        playSlider->setObjectName(QStringLiteral("playSlider"));
        playSlider->setGeometry(QRect(110, 430, 601, 22));
        playSlider->setMaximum(999);
        playSlider->setOrientation(Qt::Horizontal);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(790, 0, 62, 25));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        minButton = new QPushButton(horizontalLayoutWidget);
        minButton->setObjectName(QStringLiteral("minButton"));

        horizontalLayout_3->addWidget(minButton);

        maxButton = new QPushButton(horizontalLayoutWidget);
        maxButton->setObjectName(QStringLiteral("maxButton"));

        horizontalLayout_3->addWidget(maxButton);

        closeButton = new QPushButton(horizontalLayoutWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout_3->addWidget(closeButton);

        vowScreen = new VideoOpenGLWidget(centralWidget);
        vowScreen->setObjectName(QStringLiteral("vowScreen"));
        vowScreen->setGeometry(QRect(0, 0, 852, 520));
        VideoPlayerClass->setCentralWidget(centralWidget);
        vowScreen->raise();
        pushButton->raise();
        pauseButton->raise();
        playButton->raise();
        playSlider->raise();
        horizontalLayoutWidget->raise();

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
