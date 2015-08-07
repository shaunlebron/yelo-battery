#pragma once
#include "CallFunctionHook.h"
#include <d3dx9.h>

namespace Fov
{
	void Initialize(D3DPRESENT_PARAMETERS *pPP);
	void Update();
	void Scale();

	void OnLostDevice();
	void OnResetDevice(D3DPRESENT_PARAMETERS *pPP);
	void Release();
}