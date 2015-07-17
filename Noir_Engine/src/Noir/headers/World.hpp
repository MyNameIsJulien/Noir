/*
	This file is part of Noir game engine.
	
	A "World" instance holds any entity created within a worlds.
	It also manages its components and corresponding systems.
	
	History:
		09/07/2015	Started creating the class.

*/
#ifndef ECS_WORLD_HPP
#define ECS_WORLD_HPP

#include "SignalManager.hpp"
#include <vector>

namespace Noir{
	namespace Entity{
		
		class Entity;
		class ISystem;
		class ISlot;
		
		class World final{
			private:

				std::vector<ISystem*> 		system_list;	// Holding all systems
				std::vector<unsigned long>	entity_IDs;		// Holding all currently
															// active IDs
				std::vector<unsigned long>	open_IDs;		// Holding all open IDs
				
				SignalManager				signalManager;		// Manages all signals ect.
			
			public:
				
				// Methods for managing systems
				void addSystem(ISystem& system);		// Adds a system to this world.
															// Only one system of a TYPE allowed.
															// TODO:
															// Rework comment.
				void rmSystem(ISystem& system);
				
				// Methods for managing entities
				Entity 	createEntity();							// Creates an entity
				void	destroyEntity(Entity& entity);			// Destroys an entity
				void 	clear();								// Destroys all entities
				SignalManager getSignalManager();						// Returns the current manager
				
				// Methods for managing components
				template<typename Component, typename... Args>
				Component addComponent(const Entity& entity,
					Args... args)
				{	
					Component component = Component(std::forward<Args>(args)...)
					for(ISystem* pSystem : system_list)
						pSystem->ProcessSystemMessage(
								SystemMessage(MessageID::COMPONENT_ADDED, component);
						)
						
					for(ISlot* pSlot :)
					return component;
				}
				
				template<typename Component>
				void rmComponent(const Entity& entity)
				{
					for(ISystem* pSystem : system_list)
						processSystemMessage(
							MessageID::COMPONENT_REMOVED, entity.getID(), Component::getID());
				}
				
		};
		
	}
}

#endif