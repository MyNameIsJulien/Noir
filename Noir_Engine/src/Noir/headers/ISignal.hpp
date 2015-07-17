/*
	This file is part of the Noir game engine.
	
	The "IMessage" class is merely an interface class
	to be implemented by concrete Message Payloads.
	
	History:
		16/07/2015	Created interface.
		17/07/2015	Fixed mistake: d'tor not public
					Renamed file from IMessage to ISignal
*/

namespace Noir{
	namespace Entity{
		
		class ISignal{
			public:
				virtual ~ISignal() {};
		};
		
	}
}