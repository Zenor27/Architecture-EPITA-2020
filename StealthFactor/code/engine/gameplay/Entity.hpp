#pragma once

#include <algorithm>
#include <set>
#include <memory>
#include <engine/gameplay/Component.hpp>

namespace engine
{
	namespace gameplay
	{
		struct EntityContext;

		class Entity
		{
		public:
			Entity(EntityContext& context);
			virtual ~Entity() = default;

			void update();
			void onTransformChange();

			EntityContext& getEntityContext() const;

			template <typename COMPONENT>
			void addComponent();

			template <typename COMPONENT>
			COMPONENT* getComponent() const;

		private:
			using ComponentPtr = std::unique_ptr<Component>;

			std::set<ComponentPtr> _components;
			EntityContext& _context;
		};


		template<typename COMPONENT>
		inline void Entity::addComponent()
		{
			auto componentPtr = std::make_unique<COMPONENT>(*this);
			_components.insert(componentPtr);
		}

		template<typename COMPONENT>
		inline COMPONENT* Entity::getComponent() const
		{
			auto begin = std::begin(_components);
			auto end = std::end(_components);

			auto iterator = std::find_if(begin, end, [](const ComponentPtr& c) {
				return dynamic_cast<COMPONENT*>(c.get()) != nullptr;
				});

			if (iterator != end)
				return reinterpret_cast<COMPONENT*>(iterator->get());
			return nullptr;
		}
	}
}
