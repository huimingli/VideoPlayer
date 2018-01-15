#pragma once

#include <QOpenGLWidget>
#include "ui_VideoOpenGLWidget.h"
#include<opencv2/core.hpp>
class VideoOpenGLWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	VideoOpenGLWidget(QWidget *parent = Q_NULLPTR);
	virtual ~VideoOpenGLWidget();
	void paintEvent(QPaintEvent * e);
public slots:
	void setImage(cv::Mat);
private:
	Ui::VideoOpenGLWidget ui;
	QImage img;
};
