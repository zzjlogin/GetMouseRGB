#include "GetMouseRGB.h"

GetMouseRGB::GetMouseRGB(QWidget *parent)
    : QMainWindow(parent)
{

    ui.setupUi(this);

	this->setMaximumSize(this->size());
	this->setMinimumSize(this->size());

	//右上角只有一个关闭按钮，和原始窗口关闭按钮一致
	this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);

	connect(&MonitorThread, &MonitorRgbThread::hasRGB, this, &GetMouseRGB::getRGB);
	MonitorThread.start();

}

//void GetMouseRGB::changeEvent(QEvent *event)
//{
//	QWidget::changeEvent(event);
//	if (event->type() == QEvent::ActivationChange)
//	{
//		if (this->isActiveWindow())
//		{
//			// widget is now active
//			return;
//		}
//		else
//		{
//
////			activateWindow();
////			setWindowState((windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
////			raise();//必须加，不然X11会不起作用
////#ifdef Q_OS_WIN32 //windows必须加这个，不然windows10 会不起作用，具体参看activateWindow 函数的文档
////			HWND hForgroundWnd = GetForegroundWindow();
////			DWORD dwForeID = ::GetWindowThreadProcessId(hForgroundWnd, NULL);
////			DWORD dwCurID = ::GetCurrentThreadId();
////
////			::AttachThreadInput(dwCurID, dwForeID, TRUE);
////			::SetForegroundWindow((HWND)winId());
////			::AttachThreadInput(dwCurID, dwForeID, FALSE);
////
////
////#endif // MAC_OS
//
//			setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
//			::SetWindowPos((HWND)winId(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
//			
//			//休眠10毫秒
//			//QThread::msleep(1000);
//			////主窗体显示堆栈置顶
//			//this->raise();
//			////显示窗体
//			//this->show();
//			////激活主窗体
//			//this->activateWindow();
//			//// widget is now inactive
//
//		}
//	}
//}

void GetMouseRGB::getRGB()
{
	g_mutex.lock();
	QString rgb_show = g_rgb[0];
	QString rgb0x_show = g_rgb[1];
	g_rgb.clear();
	g_mutex.unlock();

	QClipboard *clipboard = QApplication::clipboard();
	clipboard->clear();
	clipboard->setText(rgb_show);

	ui.lineEdit_RGB->setText(rgb_show);
	ui.lineEdit_0xRGB->setText(rgb0x_show);
	
	
	return;
}

/*
void GetMouseRGB::keyPressEvent(QKeyEvent *event)
{
	int keyVal = event->key();

	if (event->modifiers() == Qt::ControlModifier && keyVal == Qt::Key_Q)
	{

		POINT Mouse_X_Y;	//存放鼠标坐标结构体
		if (FALSE == GetCursorPos(&Mouse_X_Y)) {	//获取鼠标坐标
			return;
		}
		HDC hdc = GetDC(NULL);
		COLORREF Windows_Hdc_RGB = GetPixel(hdc, Mouse_X_Y.x, Mouse_X_Y.y);	//获取指定DC上的像素点RGB值
		
		
		//获取RGB，其可以使用：GetRValue,GetGvalue,GetBvalue函数代替
		WORD r = Windows_Hdc_RGB & 0x000000FF;
		WORD g = (Windows_Hdc_RGB & 0x0000FF00) >> 8;
		WORD b = (Windows_Hdc_RGB & 0x00FF0000) >> 16;
		
		
		
		QString rgb("");
		rgb += QString::number(r);
		rgb += ",";
		rgb += QString::number(g);
		rgb += ",";
		rgb += QString::number(b);
		ui.lineEdit_RGB->setText(rgb);

		QString hexRGB("");
		hexRGB = QString("%1").arg(r,2,16,QLatin1Char('0'));
		hexRGB += QString("%1").arg(g, 2, 16, QLatin1Char('0'));
		hexRGB += QString("%1").arg(b, 2, 16, QLatin1Char('0'));
		hexRGB = hexRGB.toUpper();
		ui.lineEdit_0xRGB->setText(hexRGB);
		
		QClipboard *clipboard = QApplication::clipboard();
		clipboard->clear();
		clipboard->setText(rgb);
	}

}
*/