/*

	This file is part of the noir project.
	https://github.com/MyNameIsJulien/Noir
	 
	 The "Entity" class is a convenience class wrapping and ID (unsigned long).

*/

#ifndef NOIR_ENTITY_HEADER
#define NOIR_ENTITY_HEADER

#include "World.hpp"
#include "Entity.hpp"

namespace Noir{
	namespace ECS{
		
		Entity::~Entity()
		{
			// TODO:
			// Finish this.
		}
		
unsigned long Entity::getID()
		{
			return ID;
		}
		
	}
}

#endif