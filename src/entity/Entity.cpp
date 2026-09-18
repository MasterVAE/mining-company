#include <utility>
#include <string>
#include <iostream>

#include "entity/Entity.hpp"

Entity::Entity(EntityType type, std::string name, double x, double y, bool is_static)
{
    type_ = type;
    name_ = name;
    x_ = x;
    y_ = y;
    is_static_ = is_static;
}

Entity::~Entity() { }

const std::string& Entity::GetName() const
{
    return name_;
}

const double Entity::X() const 
{
    return x_;
}

const double Entity::Y() const 
{
    return y_;
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
        module->Start();
    }
}

void Entity::Update()
{
    for(auto& module : modules_)
    {
        module->Update();
    }
}

const std::vector<std::unique_ptr<Module>>& Entity::GetModules() const
{
    return modules_;
}

const Module* Entity::GetModule(ModuleType type) const
{
    for(const auto& module : modules_)
    {
        if(module->GetType() == type) return module.get();
    }

    return nullptr;
}

const std::vector<std::string> Entity::GetData() const
{
    std::vector<std::string> data;
         std::cout << "data asked" << modules_.size() << std::endl;
    for(const auto& module : modules_)
    {
        std::string module_data = module->GetData();
        std::cout << "data getted" << module_data << std::endl;
        if(module_data != "")  data.push_back(module_data);
    }

    return data;
}

void Entity::AddModule(std::unique_ptr<Module> module) 
{
    modules_.push_back(std::move(module)); 
}