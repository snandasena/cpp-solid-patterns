//
// Created by sajith on 3/25/21.
//

#ifndef SOLID_PLANTCARETAKER_H
#define SOLID_PLANTCARETAKER_H

namespace caretaker
{
    class PlantCareTaker
    {
        bool windowBlindsOpen = true;

    public:
        void pourWater();
        void sprinkleWater();

        void openWindowBlinds();
        void closeWindowBlinds();
    };
} // namespce caretaker

#endif //SOLID_PLANTCARETAKER_H
