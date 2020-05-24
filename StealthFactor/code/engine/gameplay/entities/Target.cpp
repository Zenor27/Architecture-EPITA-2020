#include "Target.hpp"

#include <engine/gameplay/EntityContext.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Target::Target(EntityContext &context)
				: Entity{ context }
			{
				_shapeList = context.graphicsManager.createShapeList("target");

				_collisionGeomId = _context.physicsManager.createCollisionBox(this, gameplay::Manager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f);
			}

			Target::~Target()
			{
				_context.graphicsManager.destroyShapeList(_shapeList);
				_context.physicsManager.destroyCollisionBox(_collisionGeomId);
			}

			void Target::update()
			{
				auto &position = getPosition();
				dGeomSetPosition(_collisionGeomId, position.x, position.y, 0);
			}

			void Target::setTransform()
			{
				_context.graphicsManager.setShapeListTransform(_shapeList, getTransform());
			}
		}
	}
}
