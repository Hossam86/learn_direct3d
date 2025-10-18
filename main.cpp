#include "Window.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
					 LPSTR lpCMDLine, int nCmdShow)
{
	// create instance of window class
	Window wnd(800, 170, "Donkey Fart Box");
	Window wnd2(200, 650, "Donkey Fart Box2");

	MSG msg;
	BOOL gResult;

	while (gResult = (GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
	return 0;
}
