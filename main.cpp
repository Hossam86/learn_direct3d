#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
					 LPSTR lpCMDLine, int nCmdShow)
{
	// first configuration class
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hbrBackground = nullptr;
	wc.hIconSm = nullptr;
	const auto pClassName = "hw3butts";
	wc.lpszClassName = pClassName;

	// register window class
	RegisterClassEx(&wc);

	// create instance of window class
	HWND hWnd =
		CreateWindowExA(0, pClassName, "Happy Hard Window",
						WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 200, 200, 640,
						480, nullptr, nullptr, hInstance, nullptr);

	ShowWindow(hWnd, SW_SHOW);

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
