#pragma once
#include <QTimer>
#include <QDebug>
#include <QString>
#include <Windows.h>
#include <QStringList>
#include "gData.h"

//int globlePid = 0;
extern HHOOK keyHook;
extern HHOOK mouseHook;


extern void GetMousePointRGB();


//键盘钩子过程
extern LRESULT CALLBACK keyProc(int nCode, WPARAM wParam, LPARAM lParam);

//鼠标钩子过程
extern LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam);

//卸载钩子
extern void unHook();


//安装钩子,调用该函数即安装钩子
extern void setHook();
