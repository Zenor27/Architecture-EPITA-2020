#pragma once

#include <ode/collision.h>
#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/Entity.hpp>
#include <engine/gameplay/EntityContext.hpp>

namespace engine
{
	namespace gameplay
	{
		struct EntityContext;
		class Entity;

		namespace entities
		{
			class Character : public gameplay::Entity
			{
			public:
				Character(gameplay::EntityContext& entityContext);
				virtual ~Character();

				virtual void draw() override;

			protected:
				graphics::ShapeList shapeList;
				dGeomID collisionGeomId;

				bool isWalking{ false };
			};
		}
	}
}
