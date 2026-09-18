#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <raylib.h>

#include "world/World.hpp"
#include "render/Render.hpp"
#include "user/User.hpp"


int main() 
{
 
    World* world = new World();
    world->Start();
    
    UserStart(world);

    RenderStart();


    while (1) 
    {
        world->Update();

        bool close = RenderWorld(world);
        if(close) break;
    }

    RenderEnd();


    delete world;

    return 0;
}