/*
	This file is part of Noir game engine.
	For further informations see World.hpp.
*/
#ifndef ECS_WORLD_CPP
#define ECS_WORLD_CPP

#include "World.hpp"
#include "ISystem.hpp"
#include "Entity.hpp"
#include <typeinfo>

namespace Noir{
	namespace Entity{
		
void	World::addSystem(ISystem& system)
		{
			for(ISystem* pSystem : system_list)
				if(typeid(pSystem).name() == typeid(system).name())
					return;
			
			system_list.push_back(&system);
		}
		
void 	World::rmSystem(ISystem& system)
		{
			for(int i=0; i < system_list.size(); i++)
				{
					if(typeid(&system_list[i]).name() == typeid(system).name())
						system_list.erase(system_list.begin() + i);
				}
		}
		
Entity	World::createEntity()
		{
			unsigned long ID = 0;
			
			if(open_IDs.empty() && !entity_IDs.empty())
			{
				ID = entity_IDs.back() + 1;
				entity_IDs.push_back(ID);
			}
			else if(!open_IDs.empty())
			{
				ID = open_IDs.back();
				open_IDs.pop_back();
			}
			else
				ID = 1;
				
			// TODO:
			// Inform systems.

			return Entity(this, ID);
		}
		
SignalManager World::getSignalManager()
		{
			return this->signalManager;
		}
		
void	World::destroyEntity(Entity& entity)
		{
			unsigned long ID = entity.getID();
			for(int i=0; i < entity_IDs.size(); i++)
				if(ID = entity_IDs[i])
				{
					entity_IDs.erase(entity_IDs.begin() + i);
					open_IDs.push_back(ID);
						
					// TODO:
					// Inform systems.
				}
		}
		
void	World::clear()
		{
			// TODO:
			// Inform systems.		
			entity_IDs.clear();
			open_IDs.clear();
		}
		

		
	}
}

#endif