/*
	This file is part of the Noir game engine.
	
	The "ISystem" class is merely an interface
	being implemented by concrete systems.
	
	History:	
		09/07/2015	Interface created.
		17/07/2015	Applied to new message system.
*/
#ifndef ECS_ISYSTEM_HPP
#define ECS_ISYSTEM_HPP

#include "ISlot.hpp"

namespace Noir{
	namespace Entity{
				
		class ISystem : public ISlot{
			public:
				ISystem() {};
				virtual ~ISystem() = 0;	
				virtual void processEntites() = 0;	
		};
		
	}
}

#endif
