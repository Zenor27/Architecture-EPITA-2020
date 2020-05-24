#include "engine/graphics/GraphicsManager.hpp"

#include <cassert>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/Event.hpp>
#include <engine/input/InputManager.hpp>
#include <engine/graphics/ShapeList.hpp>
#include <engine/graphics/ViewProvider.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/Engine.hpp>

namespace engine
{
	namespace graphics
	{
		Manager::Manager(EventListener& eventListener, ViewProvider& viewProvider)
			: _eventListener{ eventListener }
			, _viewProvider{ viewProvider }
		{
		}

		bool Manager::setUp()
		{
			_window.create(sf::VideoMode{ (unsigned int)WINDOW_WIDTH, (unsigned int)WINDOW_HEIGHT }, "Stealth Factor");

			if (!_window.isOpen())
			{
				return false;
			}

			_window.setVerticalSyncEnabled(true);

			return true;
		}

		void Manager::tearDown()
		{
			_window.close();
		}

		void Manager::update()
		{
			sf::Event event;
			while (_window.pollEvent(event))
			{
				_eventListener.onEvent(event);
			}
		}

		void Manager::clear()
		{
			_window.clear(sf::Color::Black);

			sf::View view{ _viewProvider.getViewCenter(), sf::Vector2f{(float)WINDOW_WIDTH, (float)WINDOW_HEIGHT} };
			_window.setView(view);
		}

		void Manager::draw()
		{
			clear();

			for (auto& shape : _shapeLists)
			{
				sf::RenderStates renderStates{ shape->getTransform() };
				for (auto& sfShape : shape->getShapes())
				{
					_window.draw(*sfShape, renderStates);
				}
			}

			_window.display();
		}

		void Manager::display()
		{
			_window.display();
		}

		ShapeList* Manager::createShapeList(const std::string& name)
		{
			ShapeList* shapeList = new ShapeList();
			std::unique_ptr<ShapeList> shapeListUniquePtr{ shapeList };
			shapeListUniquePtr->load(name);

			_shapeLists.insert(std::move(shapeListUniquePtr));

			return shapeList;
		}
		void Manager::destroyShapeList(ShapeList* shapeList)
		{
			auto iterator = std::find_if(std::begin(_shapeLists), std::end(_shapeLists), [shapeList](const ShapeListPtr& shapeListPtr)
				{
					return shapeListPtr.get() == shapeList;
				});
			_shapeLists.erase(iterator);
		}
		void Manager::setShapeListTransform(ShapeList* shapeList, sf::Transform transform)
		{
			shapeList->setTransform(transform);
		}
	}
}
