//
// Created by sajith on 3/30/21.
//


#include <iostream>

template<typename T>
concept Flyable = requires(T t)
{
    t.fly();
};


template<typename T> concept Swimable =
requires(T t)
{
    t.swim();
};

template<Flyable T>
void action(const T t)
{
    std::cout << "Let's fly\n";
    t.fly();
}

template<Swimable T>
void action(const T &t)
{
    std::cout << "Let's swim\n";
    t.swim();
}

class Bird
{
public:
    void fly() const
    {
        std::cout << "Fly...\n";
    }
};

class Fish
{
public:
    void swim() const
    {
        std::cout << "Swim...\n";
    }
};


int main()
{
    Bird bird;
    Fish fish;
    action(bird);

    return 0;
}




