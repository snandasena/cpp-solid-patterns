//
// Created by sajith on 4/20/21.
//

#ifndef SOLID_WATERDEVICE_H
#define SOLID_WATERDEVICE_H

namespace interfaces
{
    class WaterDevice
    {
    public:
        virtual ~WaterDevice() = default;
        virtual void pourWater() = 0;
        virtual void sprinkleWater() = 0;
    };
}

#endif //SOLID_WATERDEVICE_H
