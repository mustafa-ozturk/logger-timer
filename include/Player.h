#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
    std::string GetName() override
    {
        return "Player";
    };

    std::string GetId() override
    {
        return "someid";
    }
};