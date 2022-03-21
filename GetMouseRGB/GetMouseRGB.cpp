#include "GetMouseRGB.h"

GetMouseRGB::GetMouseRGB(QWidget *parent)
    : QMainWindow(parent)
{

    ui.setupUi(this);

	this->setMaximumSize(this->size());
	this->setMinimumSize(this->size());

	//���Ͻ�ֻ��һ���رհ�ť����ԭʼ���ڹرհ�ťһ��
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
////			raise();//����ӣ���ȻX11�᲻������
////#ifdef Q_OS_WIN32 //windows������������Ȼwindows10 �᲻�����ã�����ο�activateWindow �������ĵ�
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
//			//����10����
//			//QThread::msleep(1000);
//			////��������ʾ��ջ�ö�
//			//this->raise();
//			////��ʾ����
//			//this->show();
//			////����������
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

		POINT Mouse_X_Y;	//����������ṹ��
		if (FALSE == GetCursorPos(&Mouse_X_Y)) {	//��ȡ�������
			return;
		}
		HDC hdc = GetDC(NULL);
		COLORREF Windows_Hdc_RGB = GetPixel(hdc, Mouse_X_Y.x, Mouse_X_Y.y);	//��ȡָ��DC�ϵ����ص�RGBֵ
		
		
		//��ȡRGB�������ʹ�ã�GetRValue,GetGvalue,GetBvalue��������
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