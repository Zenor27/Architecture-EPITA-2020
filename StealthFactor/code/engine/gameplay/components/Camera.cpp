#include "engine/gameplay/components/Camera.hpp"

#include <engine/gameplay/Entity.hpp>
#include <engine/gameplay/EntityContext.hpp>
#include <engine/gameplay/components/Transform.hpp>
#include <engine/graphics/GraphicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			Camera::Camera(Entity& entity)
				: Component{ entity }
			{
				getEntity().getEntityContext().graphicsManager.setCamera(this);
			}

			const sf::Vector2f& Camera::getPosition() const
			{
				auto transform = getEntity().getComponent<Transform>();
				return transform->getPosition();
			}
		}
	}
}