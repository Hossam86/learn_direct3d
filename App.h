#pragma once
#include "ChiliTimer.h"
#include "Window.h"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
	~App();

private:
	void DoFrame();

private:
	Window wnd;
	ChiliTimer timer;
};