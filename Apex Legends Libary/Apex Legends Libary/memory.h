#pragma once
#include <Windows.h>
#include <string>
template <typename T>
T Read(uintptr_t Address) // replace with ur memory reading
{
	return *reinterpret_cast<T*>(Address);
}
std::string ReadString(uintptr_t Address)
{
	return "";
}
template <typename T>
T Write(uintptr_t Address,T value) // replace with ur memory reading
{
	return *reinterpret_cast<T*>(Address);
}