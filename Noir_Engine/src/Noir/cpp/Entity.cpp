#ifndef NOIR_ENTITY_IMPL
#define NOIR_ENTITY_IMPL

#include "Entity.h"
#include "World.h"

namespace Noir{
	namespace ECS{
		
		Entity::Entity(World& world, const unsigned int ID)
		{
			this->world = &world;
			this->ID	= ID;
		}
		
		Entity::Entity(const Entity& other)
		{
			this->world = other.world;
			this->ID	= other.ID;
		}
		
	}
}

#endif