#pragma once

#include <ode/collision.h>
#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/Entity.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Character : public Entity
			{
			public:
				Character(EntityContext &context);
				virtual ~Character();

				void setTransform();

			protected:
				graphics::ShapeList* _shapeList;
				dGeomID _collisionGeomId;

				bool _isWalking{ false };
			};
		}
	}
}
