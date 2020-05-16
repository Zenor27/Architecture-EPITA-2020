#pragma once

#include <set>
#include <string>
#include <SFML/System/Vector2.hpp>
#include <engine/graphics/View.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/input/InputManager.hpp>
#include <engine/gameplay/EntityContext.hpp>
#include <engine/gameplay/EntityManager.hpp>


namespace engine
{
	namespace gameplay
	{
		class Manager : public graphics::View, public EntityManager
		{
		public:
			Manager(graphics::Manager& graphicsManager, input::Manager& inputManager, physics::Manager& physicsManager);

			void update();
			void draw();

			void gameOver() override;

			sf::Vector2f getViewCenter() const override;

			void loadMap(const std::string& mapName);
			void loadNextMap() override;

			const entities::Player& getPlayer() const override;

			static const float CELL_SIZE;

		private:
			EntityContext _entityContext;

			std::set<Entity*> entities;
			entities::Player* playerEntity{};

			// Map
			std::string currentMapName;
			std::string nextMapName;
			int rows{ 0 };
			int columns{ 0 };

			bool preventMapCompletion{ false };
			bool nextMapRequested{ false };
		};
	}
}
