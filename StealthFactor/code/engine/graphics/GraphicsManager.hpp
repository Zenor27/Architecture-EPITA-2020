#pragma once

#include <memory>
#include <set>
#include <engine/graphics/ShapeList.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace engine
{
	class EventListener;

	namespace graphics
	{
		class ShapeList;
		class ViewProvider;

		class Manager
		{
		public:
			Manager(EventListener &eventListener, ViewProvider &viewProvider);

			bool setUp();
			void tearDown();

			void update();

			void clear();
			void draw();
			void display();

			ShapeList* createShapeList(const std::string& name);
			void destroyShapeList(ShapeList* shapeList);
			void setShapeListTransform(ShapeList* shapeList, sf::Transform transform);

		private:
			EventListener & _eventListener;
			ViewProvider & _viewProvider;
			using ShapeListPtr = std::unique_ptr<ShapeList>;
			std::set<ShapeListPtr> _shapeLists;

			sf::RenderWindow _window;

			static const sf::Int16 WINDOW_WIDTH = 800;
			static const sf::Int16 WINDOW_HEIGHT = 600;
		};
	}
}
