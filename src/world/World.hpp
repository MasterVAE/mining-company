#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include "entity/Entity.hpp"

class World
{
    std::vector<Entity> entities_;

public:
    World();
    ~World();

    std::vector<Entity> GetEntities();
};

#endif // WORLD_HPP