/*
	This file is part of Noir game engine.
	
	Entities are objects in the world composed with components.
	
	History:
		06/07/2015	Prototyping approach. Currently low cache coherency.
		09/07/2015	Added and implemented getID().
		
*/
#ifndef ECS_ENTITY_HPP
#define ECS_ENTITY_HPP

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
				
		};
		
	}
}


#endif