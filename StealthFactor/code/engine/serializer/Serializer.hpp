#pragma once

#include <string>

namespace engine
{
	namespace serializer
	{
		class Serializer
		{
		public:
			virtual void loadValue(const std::string& valueName, std::string& value) = 0;

			virtual void loadValue(const std::string& valueName, float& value) = 0;

			virtual void loadValue(const std::string& valueName, int& value) = 0;
		};
	}
}