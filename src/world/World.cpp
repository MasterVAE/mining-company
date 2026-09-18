#include <vector>
#include <iostream>

#include "entity/Entity.hpp"
#include "world/World.hpp"

World::World()
{

}

World::~World()
{
    entities_.clear();
}

std::vector<Entity>& World::GetEntities()
{
    return entities_;
}

void World::Start()
{
    // TODO
}

void World::Update()
{
    for(auto& entity : entities_)
    {
        entity.Update();
    }
}

Entity& World::Spawn(Entity& entity)
{
    entities_.push_back(entity);
    std::cout << "Spawned: " << entity.GetName() << std::endl;
    return *entities_.end();
}