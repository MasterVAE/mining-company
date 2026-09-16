#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <vector>

#include "entity/Entity.hpp"
#include "entity/Module.hpp"
#include "entity/Storage.hpp"

class Asteroid : Module
{
    Storage* my_storage;

public:

    void Start() override
    {
        my_storage = (Storage*)my_entity_->GetModule(MDL_Storage);
    }

    void Update() override
    {
        // TODO
    }
};

#endif //ASTEROID_HPP