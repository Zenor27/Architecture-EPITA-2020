#include "CollisionBox.hpp"

#include <engine/physics/PhysicsManager.hpp>
#include <engine/gameplay/Entity.hpp>
#include <engine/gameplay/EntityContext.hpp>
#include <engine/gameplay/components/Transform.hpp>


namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			CollisionBox::CollisionBox(Entity& entity)
				: Component{ entity }
			{
				_collisionGeomId = getPhysicsManager().createCollisionBox(&getEntity(), 0, 0);
			}

			CollisionBox::~CollisionBox()
			{
				getPhysicsManager().destroyCollisionVolume(_collisionGeomId);
			}

			physics::Manager& CollisionBox::getPhysicsManager() const
			{
				return getEntity().getEntityContext().physicsManager;
			}

			std::set<Entity*> CollisionBox::getCollisions() const
			{
				return getPhysicsManager().getCollisionsWith(_collisionGeomId);
			}
		}
	}
}