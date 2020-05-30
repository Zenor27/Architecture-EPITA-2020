#include "engine/gameplay/GameplayManager.hpp"

#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <pugixml/pugixml.hpp>
#include <engine/Engine.hpp>
#include <engine/gameplay/components/Enemy.hpp>
#include <engine/gameplay/components/Player.hpp>
#include <engine/gameplay/components/Target.hpp>
#include <engine/gameplay/components/Transform.hpp>


namespace engine
{
	namespace gameplay
	{
		const float Manager::CELL_SIZE = 50.f;

		Manager::Manager(graphics::Manager &graphicsManager, input::Manager &inputManager, physics::Manager &physicsManager)
			: _context{ graphicsManager, inputManager, physicsManager, *this }
		{
		}

		void Manager::setUp()
		{
		}

		void Manager::tearDown()
		{
			removeEntities();
		}

		void Manager::update()
		{
			for (auto &entity : _entities)
			{
				entity->update();
			}

			_preventMapCompletion = false;
			if (_nextMapRequested && !_nextMapName.empty())
			{
				_nextMapRequested = false;
				loadMap(_nextMapName);
			}
		}

		void Manager::loadMap(const std::string &mapName)
		{
			removeEntities();

			std::stringstream filename;
			filename << "maps/" << mapName << ".xml";

			pugi::xml_document doc;
			pugi::xml_parse_result result = doc.load_file(filename.str().c_str());

			if (result)
			{
				assert(!doc.empty());
				auto xmlMap = doc.first_child();

				_rows = std::stoi(xmlMap.child_value("rows"));
				assert(_rows >= 0);

				_columns = std::stoi(xmlMap.child_value("columns"));
				assert(_columns >= 0);

				// FIXME: What to do here ?
				std::unique_ptr<Entity> entity;

				for (auto &xmlElement : xmlMap.child("elements").children())
				{
					entity.reset(new Entity{ _context });
					entity->addComponent < components::Transform>();


					if (!std::strcmp(xmlElement.name(), "enemy"))
					{
						int row = std::stoi(xmlElement.child_value("row"));
						assert(row >= 0 && row < _rows);

						int column = std::stoi(xmlElement.child_value("column"));
						assert(column >= 0 && column < _columns);

						std::string archetypeName = xmlElement.child_value("archetype");

						auto enemyEntity{ new components::Enemy{ _context, archetypeName } };
						EntityPtr entity{ enemyEntity };
						entity->setPosition(sf::Vector2f{ (column + 0.5f) * CELL_SIZE, (row + 0.5f) * CELL_SIZE });
						enemyEntity->propagateTransform();

						_entities.insert(std::move(entity));
					}

					if (!std::strcmp(xmlElement.name(), "player"))
					{
						int row = std::stoi(xmlElement.child_value("row"));
						assert(row >= 0 && row < _rows);

						int column = std::stoi(xmlElement.child_value("column"));
						assert(column >= 0 && column < _columns);

						_playerEntity = new components::Player{ _context };
						EntityPtr entity{ _playerEntity };
						entity->setPosition(sf::Vector2f{ (column + 0.5f) * CELL_SIZE, (row + 0.5f) * CELL_SIZE });
						_playerEntity->propagateTransform();

						_entities.insert(std::move(entity));
					}

					if (!std::strcmp(xmlElement.name(), "target"))
					{
						int row = std::stoi(xmlElement.child_value("row"));
						assert(row >= 0 && row < _rows);

						int column = std::stoi(xmlElement.child_value("column"));
						assert(column >= 0 && column < _columns);

						auto targetEntity = new components::Target{ _context };
						EntityPtr entity{ targetEntity };
						entity->setPosition(sf::Vector2f{ (column + 0.5f) * CELL_SIZE, (row + 0.5f) * CELL_SIZE });
						targetEntity->propagateTransform();

						_entities.insert(std::move(entity));
					}

					// FIXME: Should instanciate camera
				}

				_currentMapName = mapName;
				_nextMapName = xmlMap.child_value("next_map");

				// JIRA-1337: Map is skipped.
				// This prevents the map to be completed during the first frame. I don't know why this happens.
				_preventMapCompletion = true;
			}
			else
			{
				std::cerr << "Map [" << mapName << "] parsed with errors." << std::endl;
				std::cerr << "Error description: " << result.description() << std::endl;
				std::cerr << "Error offset: " << result.offset << std::endl;
			}
		}

		void Manager::gameOver()
		{
			std::cout << "Game over" << std::endl;
			loadMap(_currentMapName);
		}

		void Manager::loadNextMap()
		{
			if (!_preventMapCompletion)
			{
				_nextMapRequested = true;
			}
		}

		const components::Player &Manager::getPlayer() const
		{
			assert(_playerEntity);
			return *_playerEntity;
		}

		void Manager::removeEntities()
		{
			_entities.clear();
			_playerEntity = nullptr;
		}
	}
}
