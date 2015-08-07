#include "Fov.h"
#include "Addresses.h"
#include <math.h>

#define DEFAULT_FOV			1.22173047065735

namespace Fov
{
	float hFov;
	float vFov = 1.25;
	float maxFov = 3.14159;
	D3DPRESENT_PARAMETERS *pPP;
	
	void Update()
	{
		float zoom = Memory::GetFloat(ADDR_FOV_ZOOM);
		if (zoom)
			Memory::SetFloat(ADDR_FOV,hFov*zoom/DEFAULT_FOV);
	}

	void Initialize(D3DPRESENT_PARAMETERS *pPP)
	{
		Fov::pPP = pPP;
		Scale();
		Memory::SetLong(ADDR_MAX_FOV_POINTER,(long)&maxFov);
	}

	void Scale()
	{
		float cam_dist = pPP->BackBufferHeight / tan( vFov / 2);
		hFov = atan( pPP->BackBufferWidth / cam_dist ) * 2;
	}

	void OnLostDevice()
	{
	}

	void OnResetDevice(D3DPRESENT_PARAMETERS *pPP)
	{
		Fov::pPP = pPP;
		Scale();
	}

	void Release()
	{
	}
}