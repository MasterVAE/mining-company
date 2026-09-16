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

const bool Entity::is_static() const
{
    return is_static_;
}

const EntityType Entity::GetType() const
{
    return type_;
}