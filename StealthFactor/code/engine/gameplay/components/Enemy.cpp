#include "Enemy.hpp"

#include <iostream>
#include <sstream>
#include <pugixml/pugixml.hpp>
#include <engine/gameplay/Entity.hpp>
#include <engine/gameplay/EntityContext.hpp>
#include <engine/gameplay/EntityListener.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/components/Player.hpp>
#include <engine/gameplay/components/Transform.hpp>


namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			Enemy::Enemy(Entity& entity)
				: Component{ entity }
			{
			}

			void Enemy::update()
			{
				auto& entity = getEntity();
				auto& context = entity.getEntityContext();

				auto& player = context.entityListener.getPlayer();
				if (player.hasJustMoved())
				{
					auto& playerPosition = player.getEntity().getComponent<Transform>()->getPosition();
					auto& myPosition = getEntity().getComponent<Transform>()->getPosition();

					auto offset = myPosition - playerPosition;

					// FIXME: Wtf
					const float CELL_SIZE = 50.f;
					offset /= CELL_SIZE;
					float distance2 = offset.x * offset.x + offset.y * offset.y;
					if (distance2 <= _visionRadius * _visionRadius)
					{
						if (_shootDelayCounter < _shootDelay)
						{
							++_shootDelayCounter;
						}
						else
						{
							getEntity().getEntityContext().entityListener.gameOver();
						}
					}
					else
					{
						_shootDelayCounter = 0;
					}
				}
			}

			void Enemy::loadArchetype(const std::string& archetypeName)
			{
				std::stringstream filename;
				filename << "archetypes/" << archetypeName << ".xml";

				pugi::xml_document doc;
				pugi::xml_parse_result result = doc.load_file(filename.str().c_str());

				if (result)
				{
					assert(!doc.empty());
					auto xmlArchetype = doc.first_child();

					std::string shapeListName = xmlArchetype.child_value("shapelist");

					_visionRadius = std::stof(xmlArchetype.child_value("vision_radius"));
					assert(_visionRadius > 0.f);

					_shootDelay = std::stoi(xmlArchetype.child_value("shoot_delay"));
					assert(_shootDelay >= 0);
				}
				else
				{
					std::cerr << "Archetype [" << archetypeName << "] parsed with errors." << std::endl;
					std::cerr << "Error description: " << result.description() << std::endl;
					std::cerr << "Error offset: " << result.offset << std::endl;
				}
			}
		}
	}
}
