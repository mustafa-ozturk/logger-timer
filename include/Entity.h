#pragma once
#include <string>

class Entity
{
public:
    virtual std::string GetName() = 0;
    virtual std::string GetId() = 0;
};