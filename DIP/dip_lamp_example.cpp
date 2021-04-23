//
// Created by sajith on 4/23/21.
//

#include <iostream>

class Lamp
{
public:
    void switchOn()
    {
        std::cout << "Lamp is on\n";
    }

    void switchOff()
    {
        std::cout << "Lamp is off\n";
    }
};

class Button
{
    Lamp &lamp;
    bool on = false;

public:
    Button(Lamp &lamp) : lamp{lamp} {}

    void toggle()
    {
        if (on)
        {
            lamp.switchOff();
        } else
        {
            lamp.switchOn();
        }

        on = !on;
    }
};

int main()
{
    Lamp lamp;
    Button button(lamp);
    button.toggle();
    button.toggle();

    return 0;
}