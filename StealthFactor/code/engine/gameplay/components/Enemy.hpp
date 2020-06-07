#pragma once

#include <string>
#include <engine/gameplay/Component.hpp>
#include <engine\gameplay\Archetype.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			class Enemy : public Component
			{
			public:
				Enemy(Entity &entity);

				void update() override;

				void setArchetype(const Archetype& archetype);

			private:
				Archetype _archetype;
				int _shootDelayCounter{ 0 };

				bool _shapeListNameHasChanged{ false };
			};
		}
	}
}
