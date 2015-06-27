/*

	This file is part of the noir project.
	https://github.com/MyNameIsJulien/Noir
	
	The "World" class manages all entites.
	It creates and deletes all entites.
	
*/

#ifndef NOIR_WORLD_HEADER
#define NOIR_WORLD_HEADER

#include "World.hpp"

namespace Noir{
	namespace ECS{
		
		World::World()
		{
			// Intentionally left blank
		}
		
Entity	World::createEntity()
		{
			
			unsigned long id = 0;
			
			if(openSet.empty() && !entityIDs.empty()
			// If there are no IDs left to be reused and Ids are already in use
			{
				id = entityIDs.back() + 1;
				entityIDs.push_back(id);
				
				return Entity(this, id);
			}
			else if(!openSet.empty())
			// If there are IDs left to be reused
			{
				id = openSet.back();
				openSet.pop_back();
				entityIDs.push_back(id);
				
				return Entity(this, id);
			}
			else
			// If no IDs are in use at all, will actually appear only once per world instance.
			{
				entityIDs.push_back(1);
				return Entity(this, 1);
			}
		}
		
void	World::destroyEntity(const Entity& entity);
		{
			openSet.push_back(entity.getID());
			entityIDs.erase(std::remove(entityIDs.begin(),
					 entityIDs.end(),
					  entity.getID()),
					   entityIDs.end());
		}
		
		
	}
}

#endif