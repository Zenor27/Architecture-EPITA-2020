#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "engine/graphics/View.hpp"
#include "engine/EventListener.hpp"
#include "engine/graphics/ShapeList.hpp"

namespace engine
{
	namespace graphics
	{
		class Manager
		{
		public:
			Manager(EventListener& eventListener, View& view);
			~Manager();

			void update();

			void clear();
			void draw(const ShapeList& shapeList, const sf::Transform& transform);
			void display();

		private:
			sf::RenderWindow window;

			static const sf::Int16 WINDOW_WIDTH = 800;
			static const sf::Int16 WINDOW_HEIGHT = 600;

			EventListener& _eventListener;
			View& _view;
		};
	}
}
