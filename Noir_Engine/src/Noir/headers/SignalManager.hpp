/*
	This file is part of the Noir game engine.
	
	The "SignalManager" class manages several signals.
	It dispatches messages to corresponding subscribers.
	
	History:
		13/07/2015 Prototype created.

*/
#ifndef ECS_SIGNALMANAGER_HPP
#define ECS_SIGNALMANAGER_HPP

namespace Noir{
	namespace Entity{
		
		class IMessage;
		
		class SignalManager final{
			public:
				void emit(IMessage& message);
				
				template<class Event>
				void subscribe()
				{
					
				}
				
		};
		
	}
}

#endif