#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <vector>

#include "entity/Entity.hpp"
#include "entity/Module.hpp"
#include "entity/Storage.hpp"

class Factory : Module
{
    std::pair<  std::vector<std::pair<std::string, size_t>>, 
                std::vector<std::pair<std::string, size_t>>> recipe_;
    Storage* my_storage;

public:
    Factory(Entity* my_entity) : Module(my_entity, MDL_Factory)
    {

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
        return "Factory";
    }
};

#endif // FACTORY_HPP