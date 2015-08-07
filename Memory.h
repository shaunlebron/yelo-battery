// Memory.h
// Module used for setting and getting values from the memory

#pragma once

#include <windows.h>

namespace Memory {
	template <typename Type> void Set(long address,Type value);
	template <typename Type> Type Get(long address);
	
	// friendlier function names for client to use
	inline void SetByte   (long address, byte   value)	{ Set<byte>   (address,value); }
	inline void SetShort  (long address, short  value)	{ Set<short>  (address,value); }
	inline void SetLong   (long address, long   value)	{ Set<long>   (address,value); }
	inline void SetFloat  (long address, float  value)	{ Set<float>  (address,value); }
	inline void SetDouble (long address, double value)	{ Set<double> (address,value); }
	
	inline byte   GetByte   (long address) { return Get<byte>   (address); }
	inline short  GetShort  (long address) { return Get<short>  (address); }
	inline long   GetLong   (long address) { return Get<long>   (address); }
	inline float  GetFloat  (long address) { return Get<float>  (address); }
	inline double GetDouble (long address) { return Get<double> (address); }
};

// Sets a type value to the address
template <typename Type> 
void Memory::Set(long address, Type value)
{
	DWORD access = PAGE_EXECUTE_READWRITE;
	int size = sizeof(Type);
	VirtualProtect((void*)address,size,access,&access);
	memcpy((void*)address,&value,size);
	VirtualProtect((void*)address,size,access,&access);
}

// Gets a type value from the address
template <typename Type> 
Type Memory::Get(long address)
{
	Type t;
	memcpy(&t,(const void*)address,sizeof(Type));
	return t;
}