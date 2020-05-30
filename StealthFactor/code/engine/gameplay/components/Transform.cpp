#include "Transform.hpp"

#include <engine/gameplay/Entity.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			Transform::Transform(Entity& entity)
				: Component{ entity }
			{
			}

			const sf::Vector2f& Transform::getPosition() const
			{
				return _position;
			}

			void Transform::setPosition(const sf::Vector2f& newPosition)
			{
				_position = newPosition;
				updateTransform();
			}

			float Transform::getRotation() const
			{
				return _rotation;
			}

			void Transform::setRotation(float newRotation)
			{
				_rotation = newRotation;
				updateTransform();
			}

			const sf::Transform& Transform::getTransform() const
			{
				return _transform;
			}

			void Transform::updateTransform()
			{
				_transform = sf::Transform::Identity;
				_transform.translate(_position);
				_transform.rotate(_rotation);

				getEntity().onTransformChange();
			}

		}
	}
}

