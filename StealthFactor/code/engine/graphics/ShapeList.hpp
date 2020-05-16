#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

namespace engine
{
	namespace graphics
	{
		class ShapeList
		{
		public:
			using Shapes = std::vector<sf::Shape *>;

			bool load(const std::string &name);

			const Shapes &getShapes() const;

		private:
			Shapes shapes;
		};
	}
}
