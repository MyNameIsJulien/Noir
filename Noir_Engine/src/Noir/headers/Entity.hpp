/*
	This file is part of Noir game engine.
	
	Entities are objects in the world composed with components.
	
	History:
		06/07/2015	Prototyping approach. Currently low cache coherency.
		09/07/2015	Added and implemented getID().
		
*/
#ifndef ECS_ENTITY_HPP
#define ECS_ENTITY_HPP

#include "IComponent.hpp"
#include <type_traits>

namespace Noir{
	namespace Entity{

		class World;
		
		class Entity final{
				private:
					
					World* world;		// Pointer to the world which holds this Entity
					unsigned long ID;	// ID of the entity
					
				public:
				
					Entity(World* world, unsigned long ID) :
						world(world), ID(ID) {};
						
					unsigned long getID();
					
					// Managing components
					template<typename Component, typename... Args>
					Component addComponent(Args... args)
					{
						static_assert(std::is_base_of<IComponent, T>, "T is not derived from IComponent!");
						return world->addComponent<Component>(this, args);
					}
					
					template<typename Component>
					void rmComponent()
					{
						static_assert(std::is_base_of<IComponent, T>, "T is not derived from IComponent!");
						world->rmComponent<Component>(this),
					}
		};
	}
}


#endif