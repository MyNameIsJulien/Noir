/*
	This file is part of the Noir game engine.
	
	This file contains several predefined signals used by the ECS.
*/
#ifndef ECS_ECSSIGNALS_HPP
#define ECS_ECSSIGNALS_HPP

#include "ISignal.hpp"

#include <typeindex>

namespace Noir{
	namespace Entity{
		
		// All signals for the entity system will need the entity ID
		class ECSSignal : public ISignal{
			private:
				unsigned long ID;
			public:
				ECSSignal(unsigned long ID) ID(ID) {};
				unsigned long getID() { return this-> ID; };
		}
		
		typedef ECSSignal Signal;
		
		class ENTITY_CREATED : public Signal{
			public:
				ENTITY_CREATED(unsigned long ID) : Signal(ID) {};
		};
		
		class ENTITY_DESTROYED : public Signal{
			public:
				ENTITY_DESTROYED(unsigned long ID) : Signal(ID) {};
		};
		
		template<typename T>
		class COMPONENT_CREATED : public Signal{
			private:
				T& component;
			public:
				COMPONENT_CREATED(unsigned long ID, T& component) : Signal(ID), component(component) {};
		}
		
		class COMPONENT_DETACHED : public Signal{
			private:
				std::type_index	component;
			public:	
				COMPONENT_DETACHED(unsigned long ID, std::type_index component) : Signal(ID), component(component) {};
				std::type_index getComponentID() { return this->component; };
		}
		
	}
}

#endif