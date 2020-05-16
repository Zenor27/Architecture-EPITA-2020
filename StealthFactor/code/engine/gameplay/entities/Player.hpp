#pragma once

#include <engine/gameplay/entities/Character.hpp>
#include <engine/gameplay/EntityContext.hpp>

namespace engine
{
	namespace gameplay
	{
		struct EntityContext;

		namespace entities
		{
			class Character;

			class Player : public Character
			{
			public:
				Player(gameplay::EntityContext& entityContext);

				virtual void update() override;

				bool hasJustMoved() const;

			private:
				bool justMoved{ false };
			};
		}
	}
}
