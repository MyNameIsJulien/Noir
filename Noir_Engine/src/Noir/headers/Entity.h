#ifndef NOIR_ENTITY_HEADER
#define NOIR_ENTITY_HEADER

namespace Noir{
	namespace ECS{
		
		class World;
		
		class Entity{
			private:
				World* world;		// Pointer to world holding this enitity
				unsigned int ID;	// ID of the entity
			
			public:
			
				// Constructor
				Entity(World& world, const unsigned int ID);
				Entity(const Entity& other);
				
				// Methods
				template<typename T>
				T addComponent()
				{
					
				}
				
				template<typename T>
				void removeComponent()
				{
					
				}
				
				template<typename T>
				T getComponent()
				{
					
				}
			
		};	
		
	}
}

#endif