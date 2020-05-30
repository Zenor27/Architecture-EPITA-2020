#pragma once

namespace engine
{
	namespace gameplay
	{
		class Entity;

		class Component
		{
		public:
			Component(Entity& entity);

			virtual ~Component() = default;

			virtual void update();
			virtual void onTransformChange();

			Entity& getEntity();
			const Entity& getEntity() const;

		private:
			Entity& _entity;
		};
	}
}