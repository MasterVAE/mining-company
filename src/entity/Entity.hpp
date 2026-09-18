#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <utility>
#include <string>
#include <vector>
#include <memory>

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
    double x_;
    double y_;
    bool is_static_;
    EntityType type_;
    std::vector<std::unique_ptr<Module>> modules_;

public:
    Entity(EntityType, std::string, double, double, bool);
    ~Entity();
    const std::string& GetName() const;
    const double X() const;
    const double Y() const;
    bool is_static() const;
    EntityType GetType() const;
    const std::vector<std::unique_ptr<Module>>& GetModules() const;
    const Module* GetModule(ModuleType type) const;
    const std::vector<std::string> GetData() const;
    void Start();
    void Update();

    void AddModule(std::unique_ptr<Module>);
};

#endif //ENTITY_HPP