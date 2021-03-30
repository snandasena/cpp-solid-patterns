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

// static polymorphism and it'll check types while compile time

// client code
template<typename Animal>
void speak(const Animal &animal) // Duck type
{
    std::cout << "Hello\n";
    animal.speak();
}

struct Tree
{

};


int main()
{
    Dog dog;
    speak(dog);

    Cat cat;
    speak(cat);

    // does not compile
//    Tree tree;
//    speak(tree);
    return 0;
}