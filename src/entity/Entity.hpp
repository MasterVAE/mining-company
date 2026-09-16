#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <utility>
#include <string>
#include <vector>

#include "entity/Module.hpp"

enum EntityType
{
    ENT_Asteroid,
    ENT_Storage,
    ENT_Factory,
    ENT_MiningShip,
    ENT_DeliveryShip
};


class Entity
{
    std::string name_;
    std::pair<double, double> coordinats_;
    bool is_static_;
    EntityType type_;
    std::vector<Module> modules_;

public:
    Entity(EntityType, std::string, std::pair<double, double>, bool);
    ~Entity();

    const std::string GetName() const;
    const std::pair<double, double> GetCooordinats() const;
    bool is_static() const;
    EntityType GetType() const;
    const std::vector<Module> GetModules() const;
    const Module* GetModule(ModuleType type) const;

    void Start();
    void Update();
};

#endif //ENTITY_HPP