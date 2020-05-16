#include "Character.hpp"

#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Character::Character(EntityContext& entityContext)
				: Entity{ entityContext }
			{
				collisionGeomId = dCreateBox(_entityContext.physicsManager.getSpaceId(), 0.f, 0.f, 0.f);
				dGeomSetData(collisionGeomId, this);
			}

			Character::~Character()
			{
				dGeomDestroy(collisionGeomId);
			}

			void Character::draw()
			{
				_entityContext.graphicsManager.draw(shapeList, getTransform());
			}
		}
	}
}
