//
// Created by sajith on 3/30/21.
//

#include <iostream>

class Animal
{
public:
    virtual ~Animal() = default;
    virtual void speak() const =0;
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


void speak(const Animal &animal)
{
    std::cout << "Hello\n";
    animal.speak();
}


int main()
{
    Dog dog;
    speak(dog);

    Cat cat;
    speak(cat);
    return 0;
}


