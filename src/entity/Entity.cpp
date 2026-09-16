#include <utility>
#include <string>

#include "entity/Entity.hpp"

Entity::Entity(EntityType type, std::string name, std::pair<double, double> coordinats, bool is_static)
{
    type_ = type;
    name_ = name;
    coordinats_ = coordinats;
    is_static_ = is_static;
}

Entity::~Entity() { }

const std::string Entity::GetName() const
{
    return name_;
}

const std::pair<double, double> Entity::GetCooordinats() const
{
    return coordinats_;
}

bool Entity::is_static() const
{
    return is_static_;
}

EntityType Entity::GetType() const
{
    return type_;
}

void Entity::Start()
{
    for(auto& module : modules_)
    {
        module.Start();
    }
}

void Entity::Update()
{
    for(auto& module : modules_)
    {
        module.Update();
    }
}

const std::vector<Module> Entity::GetModules() const
{
    return modules_;
}
const Module* Entity::GetModule(ModuleType type) const
{
    for(const auto& module : modules_)
    {
        if(module.GetType() == type) return &module;
    }

    return nullptr;
}