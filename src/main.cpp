#include <iostream>

#include "world/World.hpp"

int main()
{
    World* world = new World();

    world->Start();

    while(1)
    {
        world->Update();
    }

    delete world;

    return 0;
}