// CallFunctionHook.h
// Class for replacing the address in an asm call operation

#pragma once

#include "Memory.h"

typedef long address;

class CallFunctionHook {
   public:
	address callLocation;
	address relativeOriginal;
	address relativeDetour;
	address absoluteOriginal;
	address absoluteDetour;

	CallFunctionHook(address callLocation,void* detour);

	void* GetCallBack();
	void SetCallAddress(address relative);
	void Enable();
	void Disable();
};


/*
This macro will create a CallFunctionHook object and its detour function.
After using the macro, begin with a curly brace and start defining the detour function.
*/
#define detour(nameDetour,callLocation) \
	void nameDetour(); \
	CallFunctionHook* nameDetour##Hook = new CallFunctionHook(callLocation,nameDetour); \
	void nameDetour()

#define callback(nameDetour) \
	void* callBack = nameDetour##Hook->GetCallBack(); \
	__asm call callBack

#define enable(nameDetour)	nameDetour##Hook->Enable();

#define disable(nameDetour)	nameDetour##Hook->Disable();