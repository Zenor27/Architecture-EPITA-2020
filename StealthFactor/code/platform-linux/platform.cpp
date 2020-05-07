#include <platform/platform.hpp>

#include <unistd.h>

namespace platform
{
	bool Platform::setWorkingDirectory(const char* path)
	{
		return chdir(path) == 0;
	}
}