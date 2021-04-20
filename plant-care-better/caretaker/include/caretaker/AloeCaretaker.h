//
// Created by sajith on 4/20/21.
//

#ifndef SOLID_ALOECARETAKER_H
#define SOLID_ALOECARETAKER_H

#include "caretaker/WaterDevice.h"
#include "caretaker/WindowDevice.h"

namespace caretaker
{
    class AloeCaretaker : public interfaces::WaterDevice, public interfaces::WindowDevice
    {
        bool windowBlindsOpen = true;


    public:
        void pourWater() override;
        void sprinkleWater() override;

        void openWindowBlinds() override;
        void closeWindowBlinds() override;
    };
}

#endif //SOLID_ALOECARETAKER_H
