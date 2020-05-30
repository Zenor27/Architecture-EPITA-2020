#include "Entity.hpp"

#include <engine/gameplay/Component.hpp>

namespace engine
{
	namespace gameplay
	{
		Entity::Entity(EntityContext& context)
			: _context{ context }
		{
		}

		void Entity::update()
		{
			for (auto& c : _components)
				c->update();
		}

		void Entity::onTransformChange()
		{
			for (auto& c : _components)
				c->onTransformChange();
		}

		EntityContext& Entity::getEntityContext() const
		{
			return _context;
		}
	}
}
