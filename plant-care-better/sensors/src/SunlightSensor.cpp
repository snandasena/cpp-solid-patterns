//
// Created by sajith on 4/20/21.
//

#include <iostream>
#include <thread>
#include <random>


#include "sensors/SunlightSensor.h"

namespace sensors
{
    SunlightSensor::SunlightSensor(const std::chrono::seconds sleepTime, std::mutex &mtx) :
            sleepTime{sleepTime}, mtx{mtx} {}


    void SunlightSensor::subscribe(interfaces::WindowDevice &device)
    {
        devices.insert(&device);
    }

    [[noreturn]] void SunlightSensor::operator()()
    {
        for (;;)
        {
            std::unique_lock<std::mutex> lock(mtx);
            const auto sunlight = isSunlight();
            updateState(sunlight);
            std::cout << "Sun shines: " << std::boolalpha << sunlight << std::endl;

            if (isTooMuchSunlight(sunlight))
            {
                for (auto p: devices)
                {
                    p->closeWindowBlinds();
                }
                sensorOn = false;
            } else if (isTooLittleSunlight(sunlight))
            {
                for (auto p: devices)
                {
                    p->openWindowBlinds();
                    sensorOn = true;
                }
            }

            lock.unlock();
            std::this_thread::sleep_for(sleepTime);
        }
    }

    void SunlightSensor::updateState(const bool sunlight)
    {
        const auto currentTime = std::chrono::system_clock::now();
        if (sunlight and sensorOn)
        {
            sunlightOnFrom = sunlightOnFrom ? *sunlightOnFrom : currentTime;
            sunlightOffFrom = std::nullopt;
        } else if (not sunlight)
        {
            sunlightOffFrom = sunlightOffFrom ? *sunlightOffFrom : currentTime;
            sunlightOnFrom = std::nullopt;
        }
    }

    bool SunlightSensor::isTooMuchSunlight(const bool sunlight)
    {
        if (sunlight)
        {
            const auto timeNow = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsedSeconds = timeNow - (*sunlightOnFrom);
            return elapsedSeconds.count() > threshold;
        }
        return false;
    }

    bool SunlightSensor::isTooLittleSunlight(const bool sunlight)
    {
        if (not sunlight)
        {
            const auto timeNow = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsedSeconds = timeNow - (*sunlightOffFrom);
            return elapsedSeconds.count() > threshold;
        }
        return false;
    }

    bool SunlightSensor::isSunlight() const
    {
        /* We simulate changes of sunlight by generating random numbers that represent
         * a probability of change in sunlight: if the sun shines or not.
         */
        static bool sunShines = false;
        static std::mt19937 generator;
        auto prob = std::uniform_int_distribution<int>(1, 100)(generator);
        if (prob >= 80)
            sunShines = !sunShines;
        return sunShines;
    }

}