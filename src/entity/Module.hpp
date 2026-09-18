#ifndef MODULE_HPP
#define MODULE_HPP


enum ModuleType
{
    MDL_Storage,
    MDL_Factory,
    MDL_Asteroid
};

class Entity;

class Module
{
    ModuleType type_;

public:
    Entity* my_entity_;

    Module(Entity* my_entity, ModuleType type) 
    {
        type_ = type;
        my_entity_ = my_entity;
    };
    ~Module() {};

    ModuleType GetType() const
    {
        return type_;
    }

    virtual void Start() {};
    virtual void Update() {};
    virtual const std::string GetData() const { return "bebra"; };
};

#endif // MODULE_HPP