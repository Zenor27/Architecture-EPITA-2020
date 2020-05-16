#pragma once

#include <SFML/Graphics/Transform.hpp>
#include <engine/gameplay/EntityContext.hpp>

namespace engine
{
	namespace gameplay
	{
		struct EntityContext;

		class Entity
		{
		public:
			Entity(gameplay::EntityContext& entityContext);

			virtual ~Entity() = default;

			virtual void update() = 0;
			virtual void draw() = 0;

			const sf::Vector2f& getPosition() const;
			void setPosition(const sf::Vector2f& newPosition);

			float getRotation() const;
			void setRotation(float newRotation);

			const sf::Transform& getTransform() const;

		protected:
			gameplay::EntityContext& _entityContext;

		private:
			sf::Vector2f _position{};
			float _rotation{ 0.f };
			sf::Transform _transform;

			void updateTransform();
		};
	}
}
