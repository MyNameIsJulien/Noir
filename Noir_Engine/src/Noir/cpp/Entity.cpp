/*
	This file is part of the Noir game engine.
	For further informations see Entity.hpp.
*/
#ifndef ECS_ENTITY_CPP
#define ECS_ENTITY_CPP

#include "..\headers\Entity.hpp"

namespace Noir{
	namespace Entity{
		
unsigned long Entity::getID()
{
		return ID;
}
		
	}
}

#endif