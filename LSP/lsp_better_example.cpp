//
// Created by sajith on 4/5/21.
//

#include <iostream>

class Animal
{
public:
    virtual ~Animal() = default;
    virtual void move() = 0;
    virtual void speak() = 0;
};


class Walkable : public Animal
{
public:
    virtual void walk() = 0;
};

class Flyable : public Walkable
{
public:
    virtual void fly() = 0;
};


class Eagle : public Flyable
{
public:
    void speak()
    {
        std::cout << "Eagle speaking\n";
    }

    void walk()
    {
        std::cout << "Eagle walking\n";
    }

    void fly()
    {
        std::cout << "Eagle flying\n";
    }

    void move()
    {
        fly();
    }
};


class Dog : public Walkable
{
public:
    void speak()
    {
        std::cout << "Dog speaking\n";
    }

    void walk()
    {
        std::cout << "Dog walking\n";
    }

    void move()
    {
        walk();
    }
};


void foo(Animal &animal)
{
    animal.move();
    animal.speak();
}

void bar(Flyable &flyable)
{
    flyable.fly();
}

void bar(Walkable &walkable)
{
    walkable.walk();
}

int main()
{
    Eagle eagle;
    Dog dog;

    foo(eagle);
    bar(eagle);

    foo(dog);
    bar(dog);

    return 0;
}

