#include <platform/platform.hpp>

#include <windows.h>

namespace platform
{
	bool Platform::setWorkingDirectory(const char* path)
	{
		wchar_t windowsPath[4096];
		MultiByteToWideChar(CP_ACP, 0, path, -1, windowsPath, 4096);
		return SetCurrentDirectory(windowsPath) != 0;
	}
}