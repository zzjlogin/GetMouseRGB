#pragma once
#include <QThread>
#include "gData.h"
#include <QMutex>
#include "LocalHook.h"

class MonitorRgbThread :
	public QThread
{
	Q_OBJECT


public:
	MonitorRgbThread();
	~MonitorRgbThread();

	void stop();

protected:
	void run();


signals:
	void hasRGB();

private:
	
	bool getHasRGB();

	bool isRun;


};

