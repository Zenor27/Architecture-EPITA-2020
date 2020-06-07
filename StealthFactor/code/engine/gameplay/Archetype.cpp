#include "Archetype.hpp"

#include <engine/serializer/Serializer.hpp>

namespace engine
{
	namespace gameplay
	{
		void Archetype::load(serializer::Serializer& serializer)
		{
			serializer.loadValue("shapelist", shapeListName);
			serializer.loadValue("vision_radius", visionRadius);
			serializer.loadValue("shoot_delay", shootDelay);
		}
	}
}


