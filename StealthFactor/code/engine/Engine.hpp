#pragma once

#include <string>
#include "EventListener.hpp"
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/input/InputManager.hpp>
#include <engine/physics/PhysicsManager.hpp>

namespace engine
{
	class Engine: public EventListener
	{
	public:
		Engine();

		void loadConfiguration();

		void run();
		float getDeltaTime() const;

		void exit();

		void onEvent(const sf::Event& event) override;

	private:
		bool running;
		float deltaTime;

		// Configuration
		std::string startMap;

		// Managers instances of managers
		graphics::Manager _graphicsManager;
		gameplay::Manager _gameplayManager;
		input::Manager _inputManager;
		physics::Manager _physicsManager;
	};
}
