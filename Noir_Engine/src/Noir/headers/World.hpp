/*

	This file is part of the noir project.
	https://github.com/MyNameIsJulien/Noir
	
	The "World" class manages all entites.
	It creates and deletes all entites.

*/

#ifndef NOIR_WORLD_HEADER
#define NOIR_WORLD_HEADER

#ifdef API_EXPORTS && _MSC_VER
	#define API __declspec(dllexport) 
#elif _MSC_VER
	#define API __declspec(dllimport)
#endif

#include <vector>

#include "Entity.hpp"

namespace Noir{
	namespace ECS{
		
		
		class API World{
			private:
				std::vector<unsigned long> openSet;		// Contains recycled IDs
				std::vector<unsigned long> entityIDs;	// Contains active IDs
			
			public:
				
				// Constructors
				World();
				
				// 
				// Methods
				
				// createEntity
				// Creates an entity.
				Entity createEntity();
				
				// destroyEntity
				// Desotry an entity.
				void destroyEntity(const Entity& entity);
			
		};
		
	}
}

#endif