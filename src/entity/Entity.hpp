#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <utility>
#include <string>

enum EntityType
{
    Asteroid,
    Storage,
    Factory,
    MiningShip,
    DeliveryShip
};


class Entity
{
    std::string name_;
    std::pair<double, double> coordinats_;
    bool is_static_;
    EntityType type_;
public:
    Entity(EntityType, std::string, std::pair<double, double>, bool);
    ~Entity();

    const std::string GetName() const;
    const std::pair<double, double> GetCooordinats() const;
    const bool is_static() const;
    const EntityType GetType() const;
};

#endif //ENTITY_HPP