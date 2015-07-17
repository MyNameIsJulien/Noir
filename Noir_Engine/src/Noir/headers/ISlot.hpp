/*
	This file is part of the Noir game engine.
	
	The "ISlot" class is merely an interface
	for recieving any events.
	
	History:
			16/07/2015	Created pure class.
						Added header guards, I forgot.
*/
#ifndef ECS_ISLOT_HPP
#define ECS_ISLOT_HPP

namespace Noir{
	namespace Entity{
		
		class ISlot{
			public:
				virtual void processMessage(ISignal* message) = 0;
				virtual ~ISlot() {};
		};
		
	}
}

#endif