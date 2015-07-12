/*
	This file is part of the Noir game engine.
	
	The "ISystem" class is merely an interface
	being implemented by concrete systems.
	
	History:	
		09/07/2015	Interface created.
*/
#ifndef ECS_SYSTEM_HPP
#define ECS_SYSTEM_HPP

#include "IComponent.hpp"

namespace Noir{
	namespace Entity{
		
		class Entity;
		class IBaseComponent;
		
		enum class MessageID{
			ENTITY_CREATED,
			ENTITY_DESTROYED,
			COMPONENT_ADDED,
			COMPONENT_REMOVED,
		};

		struct SystemMessage{
		
			MessageID message;
			
			unsigned long entityID;
			
			union	Payload{
					IBaseComponent&	  component;
					unsigned long componentID;
					Payload() {};
			} payload;
			
			SystemMessage()
				{
					
				}
			
			SystemMessage(const MessageID& message,
				const unsigned long entityID)
				{
					this->message = message;
					this->entityID = entityID;
				}
				
			SystemMessage(const MessageID& message,
				const unsigned long entityID,
				const IBaseComponent& component)
				{
					this->message 			= message;
					this->entityID			= entityID;
					this->payload.component = component;
				}
				
			SystemMessage(const MessageID& message,
				const unsigned long entityID,
				const unsigned long componentID)
				{
					this->message 		= message;
					this->entityID 		= entityID;
					this->payload.componentID 	= componentID;
				}
			
			// TODO:
			// 	Replace IBaseComponent in Payload by ComponentID 
			// 	and tuple with its c'tor arguments
		};
		
		class ISystem{
			
			// Have definitive constructor. Force certain meta-parameters.
			// TODO:
			// Create Component manager or smth comparable.
			public:
				ISystem() {};
				virtual ~ISystem() = 0;
				
				virtual void processEntites();	
				
				virtual void processSystemMessage(const SystemMessage& message);
			// TODO:
			// Add message system for systems.
		};
		
	}
}

#endif
