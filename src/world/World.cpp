#include <vector>

#include "entity/Entity.hpp"
#include "world/World.hpp"

World::World()
{

}

World::~World()
{
    entities_.clear();
}

std::vector<Entity> World::GetEntities()
{
    return entities_;
}