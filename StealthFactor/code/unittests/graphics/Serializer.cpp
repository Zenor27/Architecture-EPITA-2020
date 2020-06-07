#include <gtest/gtest.h>

#include <engine/serializer/XMLSerializer.hpp>
#include <engine/gameplay/Archetype.hpp>

namespace engine
{
	namespace serializer
	{
		TEST(SerializerTest, XML)
		{
			engine::serializer::XMLSerializer xmlSerializer{ "archetypes/test.xml" };

			engine::gameplay::Archetype archetype;

			archetype.load(xmlSerializer);

			EXPECT_STREQ("test", archetype.shapeListName.c_str());
			EXPECT_FLOAT_EQ(4.2f, archetype.visionRadius);
			EXPECT_EQ(42, archetype.shootDelay);
		}
	}
}