#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VideoPlayer.h"

class VideoPlayer : public QMainWindow
{
	Q_OBJECT

public:
	VideoPlayer(QWidget *parent = Q_NULLPTR);
	void timerEvent(QTimerEvent*e);
public slots:
	void openVideo();
	void play();
	void pause();
	void sliderRelease();
	void sliderPress();
	void setPos(int pos);

private:
	Ui::VideoPlayerClass ui;
	bool pressSlider;
};
