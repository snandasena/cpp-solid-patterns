//
// Created by sajith on 3/30/21.
//

#include <iostream>
// service code


class Dog
{
public:
    void speak() const
    {
        std::cout << "Bark...\n";
    }
};


class Cat
{
public:
    void speak() const
    {
        std::cout << "Meow...\n";
    }
};


// client code
template<typename Animal>
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