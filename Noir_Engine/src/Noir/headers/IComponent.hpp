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
			public:
				virtual ~IBaseComponent() = 0;
		};
		
		template<typename T>
		class IComponent : public IBaseComponent{
			public:
				virtual ~IComponent() = 0;	
				
				static unsigned long getComponentID()
				{
					// TODO:
					// Implement component manager.
					return 0;
				}
		};
		
	}
}

#endif