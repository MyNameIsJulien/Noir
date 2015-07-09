/*
	This file is part of Noir game engine.

*/
#ifndef ECS_WORLD_CPP
#define ECS_WORLD_CPP

#include "World.hpp"
#include "Entity.hpp"

namespace Noir{
	namespace Entity{
		
		World::~World()
		{
			for(Entity* pEntity : entity_list)
				delete pEntity;
				
			// TODO:
			// Remove corresponding components from sytem.
		}
		
Entity	World::createEntity()
		{
			unsigned long id = 0;
			
			if(openEntities.empty() && !entities.empty())
				id = entities.back() + 1;
			else if(!openEntities.empty())
			{
				id = openEntities.back();
				openEntities.pop_back();
			}
			
			entities.push_back(id);
			entity_list.push_back(new Entity(this, id));
			return *entity_list.back();	
		}
		
void	World::destroyEntity(const Entity& entity)
		{
			for(int i=0; i < entity_list.size(); i++)
				if(entity_list[i] == &entity)
				{
					delete entity_list[i];
					entity_list.erase(entity_list.begin() + i);
				}
				
			// TODO:
			// Remove components from system.
		}
		
	}
}

#endif