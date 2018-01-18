#include "VideoPlayer.h"
#include<iostream>
#include"VideoThread.h"
#include<QFileDialog>
#include<QMessageBox>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<QGridLayout>
#include<QHBoxLayout>

VideoPlayer::VideoPlayer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	bottomAnimation = new QPropertyAnimation(ui.bottomWidget, "geometry");
	topAnimation = new QPropertyAnimation(ui.topButtons, "geometry");
    setMouseTracking(true);
	ui.centralWidget->setMouseTracking(true);
	ui.vowScreen->setMouseTracking(true);
 
	qRegisterMetaType<cv::Mat>("cv::Mat");
	QObject::connect(VideoThread::getInstance(),
		SIGNAL(sendVideoFrame(cv::Mat)),
		ui.vowScreen,
		SLOT(setImage(cv::Mat))
	);
	isFullScreen = false;
	pause();

	startTimer(40);//启动计时器
}
void VideoPlayer::openVideo() {
	QString fileName = QFileDialog::getOpenFileName(this, "please select your video file!");
	if (fileName.isEmpty()) {
		return;
	}
	std::string file = fileName.toLocal8Bit().data();//防止有中文
	if (!VideoThread::getInstance()->openVideoFile(file)) {
		QMessageBox::information(0,"", fileName + "fail to open video");
		return;
	}

	play();
}

void VideoPlayer::timerEvent(QTimerEvent * e)
{
	if (pressSlider)
		return;
	double pos = VideoThread::getInstance()->getPos();
	ui.playSlider->setValue(pos * 1000);
	
}

void VideoPlayer::mouseDoubleClickEvent(QMouseEvent * event)
{
	if (windowState() &  Qt::WindowFullScreen)
		showNormal();
	else
		showFullScreen();
}

void VideoPlayer::resizeEvent(QResizeEvent * e)
{
	ui.vowScreen->resize(size()); 
	ui.bottomWidget->move(0, this->height() - ui.bottomWidget->height());
	ui.bottomWidget->resize(QSize(this->width(), ui.bottomWidget->height()));


	ui.playSlider->move(25, ui.playSlider->y());
	ui.playSlider->resize(this->width() - 50, ui.playSlider->height());

	ui.playButton->move(ui.bottomWidget->width() / 2 + 50, ui.playSlider->y()+30);
	ui.pushButton->move(ui.bottomWidget->width() / 2 - 50, ui.playSlider->y() + 30);

	ui.topButtons->move(this->width() - ui.topButtons->width() - 5, 5);
}

void VideoPlayer::mouseMoveEvent(QMouseEvent * event)
{
	if (isFullScreen) {
        int y = event->globalY();
	    if (y >= height() - 100 || y<=5) {
			showBottomInAnimation();
			showTopInAnimation();
	    }
	    else {
			hideBottomInAnimation();
			hideTopInAnimation();
	    }
	}
}

void VideoPlayer::play()
{
	ui.pauseButton->show();
	ui.pauseButton->setGeometry(ui.playButton->geometry());
	ui.playButton->hide();
	VideoThread::getInstance()->play();
}

void VideoPlayer::pause()
{
	ui.playButton->show();
	ui.playButton->setGeometry(ui.pauseButton->geometry());
	ui.pauseButton->hide();
	VideoThread::getInstance()->pause();
}

void VideoPlayer::sliderRelease()
{
	pressSlider = false;
}

void VideoPlayer::sliderPress()
{
	pressSlider = true;
}

void VideoPlayer::setPos(int pos)
{
	VideoThread::getInstance()->seek((double)pos / 1000);
}

void VideoPlayer::fullResetScreen()
{
	if (!isFullScreen) {
		showFullScreen();
		isFullScreen = true;
		hideBottomInAnimation();
		hideTopInAnimation();
	}
	else {
		showNormal();
		isFullScreen = false;
		showBottomInAnimation();
		showTopInAnimation();
	}
}

void VideoPlayer::showBottomInAnimation()
{
	if (ui.bottomWidget->y() == height()) {
		bottomAnimation->setDuration(500);
		bottomAnimation->setStartValue(QRect(ui.bottomWidget->x(), height(), ui.bottomWidget->width(), ui.bottomWidget->height()));

		bottomAnimation->setEndValue(QRect(ui.bottomWidget->x(), this->height() - ui.bottomWidget->height(), ui.bottomWidget->width(), ui.bottomWidget->height()));
		bottomAnimation->start();
	}
}

void VideoPlayer::hideBottomInAnimation()
{
	if (ui.bottomWidget->y() == this->height() - ui.bottomWidget->height()) {
		bottomAnimation->setDuration(500);
		bottomAnimation->setStartValue(QRect(ui.bottomWidget->x(), this->height() - ui.bottomWidget->height(), ui.bottomWidget->width(), ui.bottomWidget->height()));

		bottomAnimation->setEndValue(QRect(ui.bottomWidget->x(), this->height(), ui.bottomWidget->width(), ui.bottomWidget->height()));
		bottomAnimation->start();
	}
}

void VideoPlayer::showTopInAnimation()
{
	if (ui.topButtons->y() == -5 - ui.topButtons->height()) {
        topAnimation->setDuration(500);
	    topAnimation->setStartValue(QRect(ui.topButtons->x(), -5-ui.topButtons->height(), ui.topButtons->width(), ui.bottomWidget->height()));

	    topAnimation->setEndValue(QRect(ui.topButtons->x(), 5, ui.topButtons->width(), ui.topButtons->height()));
	    topAnimation->start();
	}
	
}

void VideoPlayer::hideTopInAnimation()
{
	if (ui.topButtons->y() == 5) {
		topAnimation->setDuration(500);
		topAnimation->setStartValue(QRect(ui.topButtons->x(), 5, ui.topButtons->width(), ui.bottomWidget->height()));

		topAnimation->setEndValue(QRect(ui.topButtons->x(), -5 - ui.topButtons->height(), ui.topButtons->width(), ui.topButtons->height()));
		topAnimation->start();
	}
}
