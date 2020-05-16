#include "engine/Engine.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include <pugixml/pugixml.hpp>
#include <SFML/System.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/input/InputManager.hpp>

namespace engine
{
	// Instanciate all managers
	Engine::Engine()
		: _gameplayManager{ _graphicsManager, _inputManager, _physicsManager }
		, _graphicsManager(*this, _gameplayManager)
	{

	}

	void Engine::loadConfiguration()
	{
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_file("configuration.xml");

		if (result)
		{
			assert(!doc.empty());
			auto configuration = doc.first_child();
			startMap = configuration.child_value("start_map");
		}
		else
		{
			std::cerr << "Configuration parsed with errors." << std::endl;
			std::cerr << "Error description: " << result.description() << std::endl;
			std::cerr << "Error offset: " << result.offset << std::endl;
		}
	}

	void Engine::run()
	{
		running = true;

		_gameplayManager.loadMap(startMap);

		sf::Clock clock;
		while (running)
		{
			deltaTime = clock.restart().asSeconds();

			_inputManager.clear();

			_physicsManager.update();
			_graphicsManager.update();
			_gameplayManager.update();

			_graphicsManager.clear();

			_gameplayManager.draw();

			_graphicsManager.display();
		}
	}

	float Engine::getDeltaTime() const
	{
		return deltaTime;
	}

	void Engine::exit()
	{
		running = false;
	}
	void Engine::onEvent(const sf::Event& event)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->exit();
			break;

		case sf::Event::LostFocus:
			_inputManager.setHasFocus(false);
			break;

		case sf::Event::GainedFocus:
			_inputManager.setHasFocus(true);
			break;

		case sf::Event::KeyPressed:
			_inputManager.onKeyPressed(event.key);
			break;

		case sf::Event::KeyReleased:
			_inputManager.onKeyReleased(event.key);
			break;

		default:
			break;
		}
	}
}
