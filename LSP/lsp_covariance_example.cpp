//
// Created by sajith on 4/12/21.
//

#include <iostream>
#include <memory>

class Animal
{
public:
    virtual ~Animal() = default;
};


class Tiger : public Animal
{
};


class Elephant : public Animal
{
};


class Zoo
{
public:
    virtual ~Zoo() = default;
    virtual Animal *free() const = 0;
};


class TigerZoo : public Zoo
{
public:
    Tiger *free() const override
    {
        return new Tiger;
    }
};

int main()
{
    TigerZoo zoo;
    auto tiger = std::unique_ptr<Animal>(zoo.free());

    return 0;
}