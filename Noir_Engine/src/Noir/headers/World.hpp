/*
	This file is part of Noir game engine.
	
	A "World" instance holds any entity created within a worlds.
	It also manages its components and corresponding systems.
	
	History:
		09/07/2015	Started creating the class.

*/
#ifndef ECS_WORLD_HPP
#define ECS_WORLD_HPP

#include <vector>
#include <memory>
#include <type_traits>
#include <typeinfo>

#include "ISystem.hpp"

namespace Noir{
	namespace Entity{
		
		class Entity;
		
		
		class World final{
			private:
				std::vector<unsigned long> 	entities;		// Containing all IDs currently used
				std::vector<unsigned long> 	openEntities;	// Containing all IDs for reuse
				std::vector<Entity*>		entity_list;	// Containing all references to entities
				std::vector<ISystem*>		system_list;	// Containing all systems
				
				// Remarks:
				// Storing pointers in standard containers
				// perhaps not a good idea.
			
			public:
				
				~World();
				
				// Methods for entity management
				Entity 	createEntity();
				void 	destroyEntity(const Entity& entity);
				
				// Methods for managing systems
				template<typename T, typename... Args>
				T* addSystem(Args... args)
				{
					static_assert(std::is_base_of<ISystem,T>::value, "World::addSystem | Argument T isn't type of ISystem.");
					for(ISystem* pSystem : system_list)
						if(typeid(T).name() == typeid(pSystem).name())
							return pSystem;
							
					T* system = new T{std::forward(args)...};
					system_list.push_back(system);
					return system_list.back();
				}
				
				template<typename T>
				void removeSystem()
				{
					static_assert(std::is_base_of<ISystem,T>::value, "World::addSystem | Argument T isn't type of ISystem.");
					for(int i=0; i < system_list.size(); i++)
						if(typeid(T).name() == typeid(system_list[i]).name())
						{
							delete entity_list[i];
							entity_list.erase(entity_list.begin() + i);
						}	
				}
				
				// Methods for component management
				template<typename T, typename... Args>
				T* addComponent(Entity&, Args... args)
				{
					static_assert(std::is_base_of<IBaseComponent,T>::value, "World::addComponent | Argument T isn't type of IBaseComponent.");
					T* component = new T{std::forward<Args>(args)...};
					return T;
				}
				
				template<typename T>
				T* getComponent(const Entity& entity)
				{
					static_assert(std::is_base_of<IBaseComponent,T>::value, "World::addComponent | Argument T isn't type of IBaseComponent.");
					return nullptr;
				}
				
				template<typename T>
				void removeComponent(const Entity& entity)
				{
					static_assert(std::is_base_of<IBaseComponent,T>::value, "World::addComponent | Argument T isn't type of IBaseComponent.");
					return nullptr;
				}
				
		};
		
	}
}

#endif