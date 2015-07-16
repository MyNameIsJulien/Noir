/*
	This file is part of the Noir game engine.
	
	The "SignalManager" class manages several signals.
	It dispatches messages to corresponding subscribers.
	
	History:
		13/07/2015 Prototype created.

*/
#ifndef ECS_SIGNALMANAGER_HPP
#define ECS_SIGNALMANAGER_HPP

#include "IMessage.hpp"
#include "ISlot.hpp"

#include <map>
#include <typeindex>
#include <vector>

namespace Noir{
	namespace Entity{
		
		class SignalManager final{
			private:
			
				std::map<std::type_index, std::vector<ISlot*>>	subscriber_map;
			
			public:
				template<class Message>
				void emit(Message* message)
				{
					static_assert(std::is_base_of(IMessage, Message), "Message is not derived from IMessage!");
					for(ISlot* pSlot : subscriber_map[std::type_index(typeid(Message))])
					{
						pSlot->processMessage(message);
					}
				}
				
				template<class Message>
				void subscribe(ISlot* slot)
				{
					subscriber_map[std::type_index(typeid(Message))].push_back(slot);
				}
				
		};
		
	}
}

#endif