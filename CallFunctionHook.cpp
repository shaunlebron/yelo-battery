// CallFunctionHook.cpp
//

#include "CallFunctionHook.h"
#include "Memory.h"

// Constructor
CallFunctionHook::CallFunctionHook(address callLocation,void* absoluteDetour)
{
	#pragma warning(disable: 4311)
	this->callLocation = callLocation;
	this->absoluteDetour = (long)absoluteDetour;
	this->relativeDetour = (long)absoluteDetour - (callLocation + 5);
	this->relativeOriginal = Memory::GetLong(callLocation + 1);
	this->absoluteOriginal = callLocation + 5 + relativeOriginal;
}

// Sets the address of the call operation
void CallFunctionHook::SetCallAddress(address relative)
{
	Memory::SetLong(callLocation + 1,relative);
}

// Enables the hook
void CallFunctionHook::Enable()
{
	SetCallAddress(relativeDetour);
}

// Disables the hook
void CallFunctionHook::Disable() 
{
	SetCallAddress(relativeOriginal);
}

// Returns the original function call
void* CallFunctionHook::GetCallBack()
{
	#pragma warning(disable: 4312)
	return (void*)absoluteOriginal;
}