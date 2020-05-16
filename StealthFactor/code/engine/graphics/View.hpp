#pragma once

#include <SFML/System/Vector2.hpp>

namespace engine
{
	namespace graphics
	{
		class View
		{
		public:
			virtual sf::Vector2f getViewCenter() const = 0;
		};
	}
}
