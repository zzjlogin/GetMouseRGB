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


//���̹��ӹ���
extern LRESULT CALLBACK keyProc(int nCode, WPARAM wParam, LPARAM lParam);

//��깳�ӹ���
extern LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam);

//ж�ع���
extern void unHook();


//��װ����,���øú�������װ����
extern void setHook();
