#pragma once

#include <engine/gameplay/entities/Player.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Player;
		}

		class EntityManager
		{
		public:
			virtual void loadNextMap() = 0;
			virtual void gameOver() = 0;
			virtual const entities::Player& getPlayer() const = 0;
		};
	}
}