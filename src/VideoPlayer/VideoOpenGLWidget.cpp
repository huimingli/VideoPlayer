#include "VideoOpenGLWidget.h"
#include<QPainter>
#include<opencv2\imgproc.hpp>

QImage * VideoOpenGLWidget::img = nullptr;
VideoOpenGLWidget::VideoOpenGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	ui.setupUi(this);
	mparent = parent;
}

VideoOpenGLWidget::~VideoOpenGLWidget()
{
}
void VideoOpenGLWidget::paintEvent(QPaintEvent * e)
{
	if (img == nullptr)
		return;
	QPainter p;
	p.begin(this);
	p.drawImage(QPoint(0, 0), *img);
	p.end();
}



void VideoOpenGLWidget::setImage(cv::Mat mat) {
	int pwidth = mparent->width();
	int pheight = mparent->height();
	static int w = 0;
	static int h = 0;
	if (w != pwidth || h != pheight)
	{
		if (img)
		{
			delete img->bits();
			delete img;
			img = nullptr;
		}
	}
	w = pwidth;
	h = pheight;
	QImage::Format fmt = QImage::Format_RGB888;
	int pixSize = 3;
	if (mat.type() == CV_8UC1) {
		fmt = QImage::Format_Grayscale8;
		pixSize = 1;
	}
	if (img == nullptr)
	{
		uchar *buf = new uchar[pwidth*height() * pixSize];
		img = new QImage(buf, pwidth, height(), fmt);
	}
	if (img->isNull() || img->format() != fmt) {
		delete img->bits();
		uchar* buf = new uchar[pwidth * pheight * pixSize];
		img = new  QImage(buf, pwidth, pheight, fmt);
	}
	 
	cv::Mat des;
	cv::resize(mat, des, cv::Size(img->size().width(), img->size().height()));
	if (pixSize > 1)
		cv::cvtColor(des, des, cv::COLOR_BGR2RGB);
	memmove(img->bits(), des.data, des.cols* des.rows*des.elemSize());
 
	update();
}