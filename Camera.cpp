#include "Camera.h"
#include "Fov.h"
#include "Addresses.h"
#include "CallFunctionHook.h"




namespace Camera
{
	detour(Update,ADDR_UPDATE_CAM)
	{
		callback(Update);
		Fov::Update();
	}

	void Initialize()
	{
		enable(Update);
	}
}