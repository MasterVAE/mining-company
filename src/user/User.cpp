#include <random>
#include <string>
#include <array>

#include "world/World.hpp"
#include "user/User.hpp"
#include "entity/Asteroid.hpp"
#include "entity/Factory.hpp"

void UserStart(World* world)
{
    // Инициализация ГПСЧ (seed из random_device, чтобы каждый запуск был разным)
    std::mt19937 rng(std::random_device{}());

    // Диапазон координат: [-5000, 5000] по обеим осям,
    // т.е. мир 10000 x 10000 с центром в (0, 0)
    constexpr int halfExtent = 3000;
    std::uniform_int_distribution<int> coordDist(-halfExtent, halfExtent);

    // Все доступные типы объектов
    constexpr std::array<EntityType, 5> types = {
        ENT_Asteroid,
        ENT_Factory,
        ENT_Storage,
        ENT_DeliveryShip,
        ENT_MiningShip
    };

    // Человекочитаемые префиксы имён, соответствующие типам
    constexpr std::array<const char*, 5> prefixes = {
        "Aster",
        "Factor",
        "Storag",
        "Deliv",
        "Miner"
    };

    // Счётчики для уникальных имён внутри каждого типа
    std::array<int, types.size()> counters{};

    std::uniform_int_distribution<size_t> typeDist(0, types.size() - 1);

    constexpr int objectCount = 50;

    for (int i = 0; i < objectCount; ++i)
    {
        size_t t = typeDist(rng);

        int x = coordDist(rng);
        int y = coordDist(rng);

        std::string name = std::string(prefixes[t]) + "_" + std::to_string(counters[t]++);


        Entity* e = new Entity(types[t], name.c_str(), x, y, t < 3);
        world->Spawn(e);

        switch (types[t])
        {
            case ENT_Asteroid:
            {
                e->AddModule((Module*)(new Asteroid(e)));
                e->AddModule((Module*)(new Storage(e)));

                break;
            }
            case ENT_Storage:
            {
                e->AddModule((Module*)(new Storage(e)));
                break;
            }
            case ENT_Factory:
            {
                e->AddModule((Module*)(new Storage(e)));
                e->AddModule((Module*)(new Factory(e)));
                break;
            }
        default:
            break;
        }
    }
}