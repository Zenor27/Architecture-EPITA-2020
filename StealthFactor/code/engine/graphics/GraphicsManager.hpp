#pragma once

#include <memory>
#include <set>
#include <SFML/Graphics/RenderWindow.hpp>
#include <engine/graphics/ShapeListId.hpp>
#include <engine/gameplay/components/Camera.hpp>

namespace engine
{
	class EventListener;

	namespace graphics
	{
		struct ShapeListInstance;
		class ViewProvider;

		class Manager
		{
		public:
			Manager(EventListener &eventListener);
			~Manager();

			bool setUp();
			void tearDown();

			void pollEvents();
			
			void setCamera(gameplay::components::Camera* camera);


			ShapeListId createShapeListInstance(const std::string &name);
			void destroyShapeListInstance(ShapeListId id);

			void setShapeListInstanceTransform(ShapeListId id, const sf::Transform &transform);

			void draw();

		private:
			using ShapeListInstancePtr = std::unique_ptr<ShapeListInstance>;

			EventListener &_eventListener;
			gameplay::components::Camera* _camera;

			sf::RenderWindow _window;

			std::set<ShapeListInstancePtr> _shapeListInstances;

			static const sf::Int16 WINDOW_WIDTH = 800;
			static const sf::Int16 WINDOW_HEIGHT = 600;
		};
	}
}
