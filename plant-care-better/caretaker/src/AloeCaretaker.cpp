//
// Created by sajith on 4/20/21.
//

#include <iostream>
#include "caretaker/AloeCaretaker.h"


namespace caretaker
{
    void AloeCaretaker::pourWater()
    {
        std::cout << "Pouring water on Aloe" << std::endl;
    }

    void AloeCaretaker::sprinkleWater()
    {
        std::cout << "Sprinkling water on Aloe" << std::endl;
    }

    void AloeCaretaker::openWindowBlinds()
    {
        if (not windowBlindsOpen)
        {
            windowBlindsOpen = true;
            std::cout << "Opened window blinds for Aloe" << std::endl;
        }
    }

    void AloeCaretaker::closeWindowBlinds()
    {
        if (windowBlindsOpen)
        {
            windowBlindsOpen = false;
            std::cout << "Closed window blinds for Aloe" << std::endl;
        }
    }
}