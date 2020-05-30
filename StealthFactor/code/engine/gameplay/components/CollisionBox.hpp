#pragma once

#include <set>
#include <ode/collision.h>
#include <SFML/System/Vector2.hpp>
#include <engine/gameplay/Component.hpp>

namespace engine
{
	namespace physics
	{
		class Manager;
	}

	namespace gameplay
	{
		namespace components
		{
			class CollisionBox : public Component
			{
			public:
				CollisionBox(Entity& entity);
				virtual ~CollisionBox();

				physics::Manager& getPhysicsManager() const;


				std::set<Entity*> getCollisions() const;

			private:
				dGeomID _collisionGeomId;
			};
		}
	}
}