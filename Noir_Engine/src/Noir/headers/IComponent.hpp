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
				virtual IBaseComponent& operator=(const IBaseComponent& other) = default;
		};
		
		
		template<class T>
		class IComponent : public IBaseComponent{
			public:
				virtual ~IComponent() = 0;	
				virtual IComponent& operator=(const IComponent& other) {};
				
				T getb() {};
				
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