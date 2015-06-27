#ifndef NOIR_WORLD_IMPL
#define NOIR_WORLD_IMPL

#include "World.h"

namespace Noir{
	namespace ECS{
		World::World()
		{
			
		}
		
Entity	World::createEntity()
		{
			unsigned int id = 0;
			
			if(openSet.empty() && !IDs.empty())
			{
				id = IDs.back() + 1;
				IDs.push_back(id);
			}
			else if(!openSet.empty())
			{
				id = openSet.back();
				openSet.pop_back();
				IDs.push_back(id);
			}
			else
			{
				id = 1;
				IDs.push_back(id);
			}
			entities.push_back(new Entity(this, id));
			return *entites.back()
		}

void	World::destroyEntity(Entity& entity)
		{
			
		}		

	}
}

#endif