//
// Created by sajith on 3/25/21.
//

#include <iostream>
#include <random>
#include <thread>


#include "sensors/MoistureSensor.h"

namespace sensors
{
    MoistureSensor::MoistureSensor(const std::chrono::seconds sleeptime, std::mutex &mtx) : sleepTime{sleeptime},
                                                                                            mtx{mtx} {}

    void MoistureSensor::subscribe(caretaker::PlantCareTaker &c)
    {
        careTakers.insert(&c);
    }

    void MoistureSensor::operator()()
    {
        for (;;)
        {
            std::unique_lock<std::mutex> lock(mtx);
            if (isAirTooDry())
            {
                for (auto p: careTakers)
                {
                    p->sprinkleWater();
                }
            }

            if (isSoilTooDry())
            {
                for (auto p: careTakers)
                {
                    p->pourWater();
                }
            }

            lock.unlock();
            std::this_thread::sleep_for(sleepTime);
        }
    }


    bool MoistureSensor::isAirTooDry()
    {
        return getAirMoisture() < threshold;
    }

    bool MoistureSensor::isSoilTooDry()
    {
        return getSoilMoisture() < threshold;
    }

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