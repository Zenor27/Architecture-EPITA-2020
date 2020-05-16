#pragma once

namespace engine
{
	namespace graphics
	{
		class Manager;
	}

	namespace input
	{
		class Manager;
	}

	namespace physics
	{
		class Manager;
	}
	namespace gameplay
	{
		class EntityManager;

		struct EntityContext
		{
			physics::Manager& physicsManager;
			graphics::Manager& graphicsManager;
			EntityManager& entityManager;
			input::Manager& inputManager;
		};
	}
}