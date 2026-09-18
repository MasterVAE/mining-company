#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include "entity/Entity.hpp"

class World
{
    std::vector<Entity*> entities_;

public:
    World();
    ~World();

    void Start();
    void Update();

    std::vector<Entity*>& GetEntities();

    Entity* Spawn(Entity* entity);
};

#endif // WORLD_HPP