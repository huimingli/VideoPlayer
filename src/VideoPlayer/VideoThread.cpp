#include "VideoThread.h"
#include<opencv2\imgcodecs.hpp>
#include<opencv2\imgproc.hpp>
#include<opencv2\highgui.hpp>
#include<QMutex>
using namespace std;
using namespace cv;
//“ª∫≈ ”∆µ‘¥
static VideoCapture cap1;
QMutex mutex;
VideoThread::VideoThread()
{
	isExit = false;
	start();
}

VideoThread::~VideoThread()
{
	mutex.lock();
	isExit = true;
	mutex.unlock();
	wait();
}

bool VideoThread::openVideoFile(const std::string file)
{
	seek(0);
	mutex.lock();
	cap1.open(file);
	mutex.unlock();
	fps = cap1.get(CAP_PROP_FPS);
	if (fps <= 0)
		fps = 25;
	return cap1.isOpened();
}

 
void VideoThread::run()
{
	  
	Mat videoFrame;
	while (true) {
		mutex.lock();
		if (isExit) {
			mutex.unlock();
			break;
		}
		if (!cap1.isOpened()) {
			mutex.unlock();
			msleep(5);
			continue;
		}

		if (!isPlaying) {
			mutex.unlock();
			msleep(5);
			continue;
		}

		if (!cap1.read(videoFrame) || videoFrame.empty()) {
			mutex.unlock();
			msleep(5);
			continue;
		}
		sendVideoFrame(videoFrame);

		int s = 0;
		s = 1000 / fps;
		msleep(s);
		mutex.unlock();
	}
}

void VideoThread::play()
{
	mutex.lock();
	isPlaying = true;
	mutex.unlock();
}

void VideoThread::pause()
{
	mutex.lock();
	isPlaying = false;
	mutex.unlock();
}

bool VideoThread::seek(double pos)
{
	double count = cap1.get(CAP_PROP_FRAME_COUNT);
	int frame = pos*count;
	return seek(frame);
}

bool VideoThread::seek(int frame)
{
	mutex.lock();
	if (!cap1.isOpened()) {
		mutex.unlock();
		return false;
	}
	int re = cap1.set(CAP_PROP_POS_FRAMES, frame);
	mutex.unlock();
	return re;
}

double VideoThread::getPos()
{
	double pos = 0;
	mutex.lock();
	if (!cap1.isOpened()) {
		mutex.unlock();
		return pos;
	}

	double count = cap1.get(CAP_PROP_FRAME_COUNT);
	double cur1 = cap1.get(CAP_PROP_POS_FRAMES);
	if (count > 0.001)
		pos = cur1 / count;
	mutex.unlock();
	return pos;
}
