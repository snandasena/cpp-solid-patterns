//
// Created by sajith on 4/23/21.
//

#include <iostream>


template<typename T> concept Switchable =
requires(T t)
{
    t.switchOn();
    t.switchOff();
};

// This is our explicit abstraction

// Client module, policy, higher layer
template<typename Switchable>
class Button
{
    Switchable &switchable;
    bool on = false;

public:
    Button(Switchable &switchable) : switchable{switchable} {}

    void toggle()
    {
        if (on)
        {
            switchable.switchOff();
        } else
        {
            switchable.switchOn();
        }

        on = !on;
    }
};


// service module, implementation details, lower layer

class Lamp1
{
public:
    void switchOn()
    {
        std::cout << "Lamp1 is on\n";
    }

    void switchOff()
    {
        std::cout << "Lamp1 is off\n";
    }
};

class Lamp2
{
public:
    void switchOn()
    {
        std::cout << "Lamp2 is on\n";
    }

    void switchOff()
    {
        std::cout << "Lamp2 is off\n";
    }
};


int main()
{
    Lamp1 lamp1;
    Button<Lamp1> button1(lamp1);
    button1.toggle();
    button1.toggle();

    Lamp2 lamp2;
    Button<Lamp2> button2(lamp2);
    button2.toggle();
    button2.toggle();

    return 0;
}

