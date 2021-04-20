//
// Created by sajith on 4/20/21.
//

#ifndef SOLID_MOISTURESENSOR_H
#define SOLID_MOISTURESENSOR_H

#include <chrono>
#include <mutex>
#include <set>

#include "caretaker/WaterDevice.h"

namespace sensors
{
    class MoistureSensor
    {
        const std::chrono::seconds sleepTime;
        std::mutex mtx;
        std::set<interfaces::WaterDevice *> devices;

        const int min = 0;
        const int max = 10;
        const int threshold = 3;

    public:
        MoistureSensor(const std::chrono::seconds, std::mutex);
        void subscribe(interfaces::WaterDevice &);
        void operator()();

    private:
        bool isAirTooDry();
        bool isSoilTooDry();
        int getAirMoisture();
        int getSoilMoisture();
    };

}

#endif //SOLID_MOISTURESENSOR_H
