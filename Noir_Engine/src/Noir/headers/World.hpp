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

namespace Noir{
	namespace Entity{
		
		class Entity;
		
		
		class World final{
			private:
				std::vector<unsigned long> 	entities;		// Containing all IDs currently used
				std::vector<unsigned long> 	openEntities;	// Containing all IDs for reuse
				std::vector<Entity*>		entity_list;	// Containing all references to entities
			
				// Remarks:
				// Storing pointers in standard containers
				// perhaps not a good idea.
			
			public:
				
				~World();
				
				// Methods for entity management
				Entity createEntity();
				void 	destroyEntity(const Entity& entity);
				
				// Methods for component management
				template<typename T, typename... Args>
				T* addComponent(Entity&, Args... args)
				{
					T* c = new T{std::forward<Args>(args)...};
					return T;
				}
				
				template<typename T>
				T* getComponent()
				{
					
				}
				
				template<typename T>
				void removeComponent()
				{
					
				}
				
		};
		
	}
}

#endif