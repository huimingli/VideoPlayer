#include "VideoPlayer.h"
#include<iostream>
#include"VideoThread.h"
#include<QFileDialog>
#include<QMessageBox>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
VideoPlayer::VideoPlayer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	qRegisterMetaType<cv::Mat>("cv::Mat");
	QObject::connect(VideoThread::getInstance(),
		SIGNAL(sendVideoFrame(cv::Mat)),
		ui.vowScreen,
		SLOT(setImage(cv::Mat))
	);

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
