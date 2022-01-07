#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GetMouseRGB.h"
#include <QKeyEvent>
#include <QPlainTextEdit> 
#include <QClipboard> 
#include <QThread>
#include <Windows.h>
#include <QThread>
#include <QString>
#include <QStringList>
#include <QMutex>
#include "gData.h"
#include "MonitorRgbThread.h"



class GetMouseRGB : public QMainWindow
{
    Q_OBJECT

public:
    GetMouseRGB(QWidget *parent = Q_NULLPTR);

	
	

private:
    Ui::GetMouseRGBClass ui;

	MonitorRgbThread MonitorThread;
	


protected:
	//重载事件
	//void changeEvent(QEvent *event);


	//按键事件
	//void keyPressEvent(QKeyEvent *event);

public slots:
	//从全局变量获取鼠标颜色信息，填充界面并复制到剪切板
	void getRGB();

};
