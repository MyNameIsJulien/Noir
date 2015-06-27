#ifndef NOIR_WORLD_HEADER
#define NOIR_WORLD_HEADER

#include "Entity.h"

#include <vector>

namespace Noir{
	namespace ECS{
		
		class World{
			private:
				std::vector<Entity*> entites;
				std::vector<unsigned int> IDs;
				std::vector<unsigned int> openSet;
			public:
				
				// Constructor
				World();
				
				// Methods
				Entity 	createEntity();
				void	destroyEntity(Entity& entity);
				
		};
		
	}
}

#endif