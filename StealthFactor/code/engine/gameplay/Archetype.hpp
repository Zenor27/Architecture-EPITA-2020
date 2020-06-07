#pragma once

#include <string>

namespace engine
{
	namespace serializer
	{
		class Serializer;
	}

	namespace gameplay
	{
		class Archetype
		{
		public:
			void load(serializer::Serializer& serializer);

			std::string shapeListName;
			float visionRadius = 0.f;
			int shootDelay = 0;
		};
	}
}