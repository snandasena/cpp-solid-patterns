//
// Created by sajith on 3/25/21.
//
#include <iostream>
#include "caretaker/PlantCaretaker.h"


namespace caretaker
{
    void PlantCareTaker::pourWater()
    {
        std::cout << "Pouring water on Aloe\n";
    }

    void PlantCareTaker::sprinkleWater()
    {
        std::cout << "Sprinkling water on Aloe\n";
    }

    void PlantCareTaker::openWindowBlinds()
    {
        if (not windowBlindsOpen)
        {
            windowBlindsOpen = true;
            std::cout << "Opened window blinds for Aloe\n";
        }
    }

    void PlantCareTaker::closeWindowBlinds()
    {
        if (not windowBlindsOpen)
        {
            windowBlindsOpen = false;
            std::cout << "Closed window blinds for Aloe\n";
        }
    }
}// namespace caretaker

