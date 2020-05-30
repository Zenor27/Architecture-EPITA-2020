#pragma once

#include <engine/gameplay/Component.hpp>
#include <SFML/Graphics/Transform.hpp>


namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			class Camera : public Component
			{
			public:
				Camera(Entity& entity);
				const sf::Vector2f& Camera::getPosition() const
			};
		}
	}
}