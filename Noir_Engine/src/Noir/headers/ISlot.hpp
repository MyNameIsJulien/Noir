/*
	This file is part of the Noir game engine.
	
	The "ISlot" class is merely an interface
	for recieving any events.
	
	History:
			16/07/2015	Created pure class.
*/

namespace Noir{
	namespace Entity{
		
		class IMessage;
		
		class ISlot{

			virtual void processMessage(IMessage* message) = 0;
			
			virtual ~ISlot() {};
		};
		
	}
}