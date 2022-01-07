#include "MonitorRgbThread.h"

MonitorRgbThread::MonitorRgbThread()
{
	setHook();
}

MonitorRgbThread::~MonitorRgbThread()
{
	this->stop();
	this->quit();
	this->wait();
	unHook();
}

void MonitorRgbThread::stop()
{
	g_mutex.lock();
	isRun = false;
	g_mutex.unlock();
}

void MonitorRgbThread::run()
{
	g_mutex.lock();
	isRun = true;
	g_hasRgb = false;
	g_mutex.unlock();

	while (isRun)
	{
		if (getHasRGB())
		{
			emit hasRGB();
			g_mutex.lock();
			g_hasRgb = false;
			g_mutex.unlock();
		}
		msleep(100);
	}
}

bool MonitorRgbThread::getHasRGB()
{
	g_mutex.lock();
	bool ret = g_hasRgb;
	g_mutex.unlock();
	return ret;
}
