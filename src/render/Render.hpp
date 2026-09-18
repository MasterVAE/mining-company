#ifndef RENDER_HPP
#define RENDER_HPP

#include "world/World.hpp"
#include "entity/Entity.hpp"

bool RenderWorld(World* world);
void RenderStart();
void RenderEnd();

#endif // RENDER_HPP