#include "LocalHook.h"

HHOOK keyHook = NULL;
HHOOK mouseHook = NULL;

void GetMousePointRGB() {
	//g_rgb.clear();
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

	QString hexRGB("");
	hexRGB = QString("%1").arg(r, 2, 16, QLatin1Char('0'));
	hexRGB += QString("%1").arg(g, 2, 16, QLatin1Char('0'));
	hexRGB += QString("%1").arg(b, 2, 16, QLatin1Char('0'));
	hexRGB = hexRGB.toUpper();
	g_mutex.lock();
	g_rgb.append(rgb);
	g_rgb.append(hexRGB);
	g_hasRgb = true;
	g_mutex.unlock();
}

//键盘钩子过程
LRESULT CALLBACK keyProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	//在WH_KEYBOARD_LL模式下lParam 是指向KBDLLHOOKSTRUCT类型地址
	KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT *)lParam;
	//如果nCode等于HC_ACTION则处理该消息，如果小于0，则钩子子程就必须将该消息传递给 CallNextHookEx
	//if (nCode == HC_ACTION){
	//if (pkbhs->vkCode == VK_ESCAPE && GetAsyncKeyState(VK_CONTROL) & 0x8000) {
	if (wParam == WM_KEYDOWN)
	{
		if (pkbhs->vkCode == 0x51 && (GetAsyncKeyState(VK_CONTROL) & 0x8000)) {

			GetMousePointRGB();
			int c = pkbhs->vkCode;
			qDebug() << pkbhs->vkCode;
			qDebug() << "ctrl + q";

			return 1;
		}

	}


	//return 1;//返回1表示截取消息不再传递,返回0表示不作处理,消息继续传递
	//}
	return CallNextHookEx(keyHook, nCode, wParam, lParam);
}

//鼠标钩子过程
LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	return 1;
}
//卸载钩子
void unHook()
{
	UnhookWindowsHookEx(keyHook);
	//  UnhookWindowsHookEx(mouseHook);
}

//安装钩子,调用该函数即安装钩子
void setHook()
{
	//这两个底层钩子,不要DLL就可以全局
	//底层键盘钩子
	keyHook = SetWindowsHookEx(WH_KEYBOARD_LL, keyProc, GetModuleHandle(NULL), 0);
	//底层鼠标钩子
	//    mouseHook =SetWindowsHookEx( WH_MOUSE_LL,mouseProc,GetModuleHandle(NULL),0);
}