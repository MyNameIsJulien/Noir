/*
	This file is part of the Noir game engine.
	
	The "Component" class is merely an interface
	being implemented by concrete components.
	
	History:
		09/07/2015 Implemented simple interface.
*/
#ifndef ECS_COMPONENT_HPP
#define ECS_COMPONENT_HPP

namespace Noir{
	namespace Entity{
		
		class IBaseComponent{
			virtual ~IBaseComponent() = 0;
		};
		
		class IComponent{
			virtual ~IComponent() = 0;	
		};
		
	}
}

#endif