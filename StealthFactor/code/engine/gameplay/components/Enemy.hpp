#pragma once

#include <string>
#include <engine/gameplay/Component.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			class Enemy : public Component
			{
			public:
				Enemy(Entity& entity);

				void update() override;

			private:
				float _visionRadius{ 0 };
				int _shootDelay{ 0 };
				int _shootDelayCounter{ 0 };

				void loadArchetype(const std::string &archetypeName);
			};
		}
	}
}
