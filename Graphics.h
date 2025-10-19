#pragma once
#include "ChiliWin.h"
#include <d3d11.h>

class Graphics
{
private:
    ID3D11Device *pDevice = nullptr;
    IDXGISwapChain *pSwap = nullptr;
    ID3D11DeviceContext *pContext = nullptr;

public:
    Graphics(HWND hWnd);
    Graphics(const Graphics &) = delete;
    Graphics &operator=(const Graphics &) = delete;
    ~Graphics();
};
