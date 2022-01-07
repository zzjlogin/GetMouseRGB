#pragma once
#include "GetMouseRGB.h"
#include <QtWidgets/QApplication>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <Windows.h>
#include <QStringList>

#include "gData.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GetMouseRGB w;

	QIcon icon;
	icon.addFile(QStringLiteral("./icon/pc.ico"), QSize(), QIcon::Normal, QIcon::Off);
	w.setWindowIcon(icon);

	//setHook();
	//w.setWindowFlags(Qt::WindowStaysOnTopHint);
	//w.setWindowFlags(w.windowFlags()&~Qt::WindowCloseButtonHint);
	//w.setWindowFlags(w.windowFlags()&~ Qt::WindowMinMaxButtonsHint);
	//w.setWindowFlags(w.windowFlags()&~Qt::WindowMaximizeButtonHint&~Qt::WindowMinimizeButtonHint);
	//最小化、最大化、关闭按钮隐藏
	//w.setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
	//w.setWindowFlags(Qt::WindowMaximizeButtonHint);
	//w.showMaximized();
	//w.showMinimized();
	w.show();

    return a.exec();
}
