//
// Created by sajith on 4/20/21.
//

#ifndef SOLID_WINDOWDEVICE_H
#define SOLID_WINDOWDEVICE_H

namespace interfaces
{
    class WindowDevice
    {
    public:
        virtual ~WindowDevice() = default;

        virtual void openWindowBlinds() = 0;
        virtual void closeWindowBlinds() = 0;
    };
}

#endif //SOLID_WINDOWDEVICE_H
