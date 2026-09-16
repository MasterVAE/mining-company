#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <string>
#include <vector>

#include "entity/Module.hpp"

class Storage : Module
{
    std::vector<std::pair<std::string, size_t>> storage_;

public:
    const std::vector<std::pair<std::string, size_t>> GetStorage() const
    {
        return storage_;
    }
    void AddToStorage(std::string object, size_t amount)
    {
        for(auto& res : storage_)
        {
            if(res.first == object)
            {
                res.second += amount;
                return;
            }
        }
        storage_.push_back(std::pair<std::string, size_t>(object, amount));
    }
    bool RemoveFromStorage(std::string object, size_t amount)
    {
        for(size_t i = 0; i < storage_.size(); i++)
        {
            if(storage_[i].first == object)
            {
                if(storage_[i].second < amount) return false;
                if(storage_[i].second > amount)
                {
                    storage_[i].second -= amount;
                    return true;
                }

                storage_.erase(storage_.begin() + i);
                return true;
            }
        }

        return false;
    }
};

#endif // STORAGE_HPP