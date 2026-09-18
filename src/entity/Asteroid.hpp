#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <vector>
#include <iostream>

#include "entity/Entity.hpp"
#include "entity/Module.hpp"
#include "entity/Storage.hpp"

class Asteroid : Module
{
    Storage* my_storage;

public:
    Asteroid(Entity* my_entity) : Module(my_entity, MDL_Asteroid)
    {
        Module(my_entity, MDL_Asteroid);
    }

    void Start() override
    {
        my_storage = (Storage*)my_entity_->GetModule(MDL_Storage);
    }

    void Update() override
    {
        // TODO
    }

    const std::string GetData() const override
    {
        std::cout << "I said asteroid" << std::endl;
        return "Asteroid";
    }
};

#endif //ASTEROID_HPP