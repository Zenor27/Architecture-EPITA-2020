#include "Character.hpp"

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
			Character::Character(EntityContext &context)
				: Entity{ context }
			{
				_collisionGeomId = _context.physicsManager.createCollisionBox(this, gameplay::Manager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f);
			}

			Character::~Character()
			{
				_context.graphicsManager.destroyShapeList(_shapeList);
				_context.physicsManager.destroyCollisionBox(_collisionGeomId);
			}

			void Character::setTransform()
			{
				_context.graphicsManager.setShapeListTransform(_shapeList, getTransform());

				auto& position = getPosition();
				dGeomSetPosition(_collisionGeomId, position.x, position.y, 0);
			}
		}
	}
}
