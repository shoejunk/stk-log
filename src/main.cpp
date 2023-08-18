// Copyright Shoejunk Industries 2023
// Log Libraries:
#include "config.h"

// System Libraries:
#include <iostream>
#include "windows.h"

void Log(char const* ksFormat, ...)
{
	va_list aList;
	va_start(aList, ksFormat);
	size_t uSize = _vscprintf(ksFormat, aList);
	char* aBuffer = new char[uSize + 1];
	vsprintf_s(aBuffer, uSize + 1, ksFormat, aList);
	OutputDebugStringA(aBuffer);
	std::cout << aBuffer;
	delete[] aBuffer;
	va_end(aList);
}

int main()
{
	Log("Log version %d.%d.%d\n", Log_VERSION_MAJOR, Log_VERSION_MINOR, Log_VERSION_PATCH);
	return 0;
}
