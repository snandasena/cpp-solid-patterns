//
// Created by sajith on 4/20/21.
//

#include <iostream>
#include <random>
#include <thread>

#include "sensors/MoistureSensor.h"


namespace sensors
{
    MoistureSensor::MoistureSensor(const std::chrono::seconds sleepTime, std::mutex &mtx) : sleepTime{sleepTime},

                                                                                            mtx{mtx} {}

    void MoistureSensor::subscribe(interfaces::WaterDevice &device)
    {
        devices.insert(&device);
    }

    [[noreturn]]void MoistureSensor::operator()()
    {
        for (;;)
        {
            std::unique_lock<std::mutex> lock(mtx);

            if (isAirTooDry())
            {
                for (auto p: devices)
                {
                    p->sprinkleWater();
                }
            }

            if (isSoilTooDry())
            {
                for (auto p: devices)
                {
                    p->pourWater();
                }
            }

            lock.unlock();
            std::this_thread::sleep_for(sleepTime);
        }
    }

    bool MoistureSensor::isAirTooDry() { return getAirMoisture() < threshold; }

    bool MoistureSensor::isSoilTooDry() { return getSoilMoisture() < threshold; }

    int MoistureSensor::getAirMoisture()
    {
        static std::mt19937 generator;
        return std::uniform_int_distribution<int>(min, max)(generator);
    }

    int MoistureSensor::getSoilMoisture()
    {
        static std::mt19937 generator;
        return std::uniform_int_distribution<int>(min, max)(generator);
    }
}

