#include "Target.hpp"

#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Target::Target(EntityContext& entityContext)
				: Entity(entityContext)
			{
				shapeList.load("target");

				collisionGeomId = dCreateBox(_entityContext.physicsManager.getSpaceId(), gameplay::Manager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f, 1.f);
				dGeomSetData(collisionGeomId, this);
			}

			Target::~Target()
			{
				dGeomDestroy(collisionGeomId);
			}

			void Target::update()
			{
				auto &position = getPosition();
				dGeomSetPosition(collisionGeomId, position.x, position.y, 0);
			}

			void Target::draw()
			{
				_entityContext.graphicsManager.draw(shapeList, getTransform());
			}
		}
	}
}
