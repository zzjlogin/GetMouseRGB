#include "LocalHook.h"

HHOOK keyHook = NULL;
HHOOK mouseHook = NULL;

void GetMousePointRGB() {
	//g_rgb.clear();
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

//���̹��ӹ���
LRESULT CALLBACK keyProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	//��WH_KEYBOARD_LLģʽ��lParam ��ָ��KBDLLHOOKSTRUCT���͵�ַ
	KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT *)lParam;
	//���nCode����HC_ACTION�������Ϣ�����С��0�������ӳ̾ͱ��뽫����Ϣ���ݸ� CallNextHookEx
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


	//return 1;//����1��ʾ��ȡ��Ϣ���ٴ���,����0��ʾ��������,��Ϣ��������
	//}
	return CallNextHookEx(keyHook, nCode, wParam, lParam);
}

//��깳�ӹ���
LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	return 1;
}
//ж�ع���
void unHook()
{
	UnhookWindowsHookEx(keyHook);
	//  UnhookWindowsHookEx(mouseHook);
}

//��װ����,���øú�������װ����
void setHook()
{
	//�������ײ㹳��,��ҪDLL�Ϳ���ȫ��
	//�ײ���̹���
	keyHook = SetWindowsHookEx(WH_KEYBOARD_LL, keyProc, GetModuleHandle(NULL), 0);
	//�ײ���깳��
	//    mouseHook =SetWindowsHookEx( WH_MOUSE_LL,mouseProc,GetModuleHandle(NULL),0);
}