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
			class Target : public Entity
			{
			public:
				Target(EntityContext &context);
				~Target();

				virtual void update() override;
				void setTransform();

			private:
				graphics::ShapeList* _shapeList;
				dGeomID _collisionGeomId;
			};
		}
	}
}
