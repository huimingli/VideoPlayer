#pragma once

#include <QThread>
#include<opencv2/core.hpp>
class VideoThread : public QThread
{
	Q_OBJECT

public:
	~VideoThread();
	static VideoThread * getInstance() {
		static VideoThread v;
		return &v;
	}
	bool openVideoFile(const std::string file);
	void run();
	void play();
	void pause();
	bool seek(double pos);
	bool seek(int frame);
	double getPos();
signals:
	void sendVideoFrame(cv::Mat);
protected:
	VideoThread();
private:
	int fps;
	bool isPlaying;
	bool isExit;
};
