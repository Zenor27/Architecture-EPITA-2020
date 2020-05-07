#pragma once

namespace platform
{
	class Platform
	{
	public:
		virtual bool setWorkingDirectory(const char* path);
	};
}