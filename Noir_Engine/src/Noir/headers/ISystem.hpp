/*
	This file is part of the Noir game engine.
	
	The "System" class is merely an interface
	being implemented by concrete systems.
	
	History:	
		09/07/2015	Interface created.
*/
#ifndef ECS_SYSTEM_HPP
#define ECS_SYSTEM_HPP

namespace Noir{
	namespace Entity{
		
		class Entity;
		
		class System{
			
			// Have definitive constructor. Force certain meta-parameters.
			System() {};
			virtual ~System() = 0;
			
			virtual void addEntity(const Entity& entity);
			virtual void removeEntity(const Entity& entity);
			
			virtual void processEntites();	
			
			// TODO:
			// Add message system for systems.
		};
		
	}
}

#endif
