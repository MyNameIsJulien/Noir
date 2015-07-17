/*
	This file is part of the Noir game engine.
	
	The "Component" class is merely an interface
	being implemented by concrete components.
	
	History:
		09/07/2015 Implemented simple interface.
		17/07/2015 Removed artefacts. Does the compiler do anything actually?
*/
#ifndef ECS_COMPONENT_HPP
#define ECS_COMPONENT_HPP

namespace Noir{
	namespace Entity{
		
		class IBaseComponent{
			public:
				virtual ~IBaseComponent() = 0;
		};
		
		
		template<class T>
		class IComponent : public IBaseComponent{
			public:
				virtual ~IComponent() = 0;	
				
				static unsigned long getID()
				{
					// TODO:
					// Implement component manager.
					return 0;
				}
		};
		
	}
}

#endif