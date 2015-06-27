/*

	This file is part of the noir project.
	https://github.com/MyNameIsJulien/Noir
	 
	 The "Entity" class is a convenience class wrapping and ID (unsigned long).

*/

#ifndef NOIR_ENTITY_HEADER
#define NOIR_ENTITY_HEADER

#ifdef API_EXPORTS && _MSC_VER
	#define API __declspec(dllexport)
#elif _MSC_VER
	#define API __declspec(dllimport)
#endif

namespace Noir{
	namespace ECS{
		
		class World;
		
		class API Entity{
			private:
				World* 			world;	// Pointer to parent world
				unsigned long	ID;		// ID
				
			public:
			
				// Constructors
				Entity(const World& world, const unsigned long ID)
					: world(world), ID(ID) {};
				Entity(const Entity& other)
					: world(other.world), ID(other.ID);
					
				~Entity();
				
				//
				// Methods
				
				// getID
				// Returns the entity's ID
				unsigned long getID();
				
				// TODO:
				// Add more methods.
		};
		
	}
}

#endif