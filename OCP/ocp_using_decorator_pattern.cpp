//
// Created by sajith on 3/31/21.
//

#include <iostream>
#include<memory>
#include <vector>
#include <cassert>

// service code
class Animal
{
public:
    virtual ~Animal() = default;
    virtual void speak() const = 0;
};


class Dog : public Animal
{
public:
    void speak() const
    {
        std::cout << "Bark...\n";
    }
};


class Cat : public Animal
{
public:
    void speak() const
    {
        std::cout << "Meow...\n";
    }
};


class AnimalDecorator : public Animal
{
    std::unique_ptr<Animal> m_Animal;
public:
    AnimalDecorator(std::unique_ptr<Animal> animal) : m_Animal{std::move(animal)}
    {
        assert(m_Animal != nullptr);
    }

    void speak() const
    {
        std::cout << "Decorated: ";
        m_Animal->speak();
    }
};


// client code
void speak(const Animal &animal)
{
    std::cout << "Hello\n";
    animal.speak();
}


int main()
{
    std::vector<std::unique_ptr<Animal>> animals;
    animals.emplace_back(std::make_unique<AnimalDecorator>((std::make_unique<Dog>())));
    animals.emplace_back(std::make_unique<Cat>());

    for (auto &animal: animals)
    {
        speak(*animal);
    }
    return 0;
}