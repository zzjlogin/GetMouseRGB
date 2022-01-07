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
	//�����¼�
	//void changeEvent(QEvent *event);


	//�����¼�
	//void keyPressEvent(QKeyEvent *event);

public slots:
	//��ȫ�ֱ�����ȡ�����ɫ��Ϣ�������沢���Ƶ����а�
	void getRGB();

};
