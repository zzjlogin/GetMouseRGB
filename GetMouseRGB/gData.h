#pragma once
#include <QString>
#include <QStringList>
#include <QMutex>
#include "MonitorRgbThread.h"

//*********************************************
extern QStringList g_rgb;

extern bool g_hasRgb;

extern QMutex g_mutex;
//*********************************************