//
// Created by sajith on 4/20/21.
//

#ifndef SOLID_CACTUSCARETAKER_H
#define SOLID_CACTUSCARETAKER_H

#include "caretaker/WaterDevice.h"

namespace caretaker
{
    class CactusCaretaker : public interfaces::WaterDevice
    {
    public:

        void pourWater() override;
        void sprinkleWater() override;
    };
}

#endif //SOLID_CACTUSCARETAKER_H
