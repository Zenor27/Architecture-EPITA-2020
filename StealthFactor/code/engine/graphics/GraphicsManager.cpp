#include "engine/graphics/GraphicsManager.hpp"

#include <cassert>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/Event.hpp>
#include <engine/input/InputManager.hpp>
#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/Engine.hpp>

namespace engine
{
	namespace graphics
	{
		Manager::Manager(EventListener& eventListener, View& view)
			: _eventListener(eventListener)
			, _view(view)
		{
			// Create view
			window.create(sf::VideoMode{ (unsigned int)WINDOW_WIDTH, (unsigned int)WINDOW_HEIGHT }, "Stealth Factor");
			window.setVerticalSyncEnabled(true);
			sf::View sfView(sf::Vector2f{ 0.f, 0.f }, sf::Vector2f{ (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT });
			window.setView(sfView);
		}

		Manager::~Manager()
		{
			window.close();
		}

		void Manager::update()
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				_eventListener.onEvent(event);
			}
		}

		void Manager::clear()
		{
			window.clear(sf::Color::Black);

			sf::View sfView{ _view.getViewCenter(), sf::Vector2f{(float)WINDOW_WIDTH, (float)WINDOW_HEIGHT} };
			window.setView(sfView);
		}

		void Manager::draw(const ShapeList& shapeList, const sf::Transform& transform)
		{
			sf::RenderStates renderStates{ transform };
			for (auto shape : shapeList.getShapes())
			{
				window.draw(*shape, renderStates);
			}
		}

		void Manager::display()
		{
			window.display();
		}
	}
}