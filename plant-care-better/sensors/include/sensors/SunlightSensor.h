//
// Created by sajith on 4/20/21.
//

#ifndef SOLID_SUNLIGHTSENSOR_H
#define SOLID_SUNLIGHTSENSOR_H

#include <chrono>
#include <mutex>
#include <optional>
#include <set>

#include "caretaker/WindowDevice.h"

namespace sensors
{
    class SunlightSensor
    {
        using TimePoint = decltype(std::chrono::system_clock::now());

        const std::chrono::seconds sleepTime;
        std::mutex mtx;
        std::set<interfaces::WindowDevice *> device;

        std::optional<TimePoint> sunlightOnFrom;
        std::optional<TimePoint> sunlightOffFrom;

        const int threshold = 2;
        bool sensorOn = true;

    public:
        SunlightSensor(const std::chrono::seconds, std::mutex &);
        void subscribe(interfaces::WindowDevice &);
        void operator()();

    private:
        void updateState(const bool);
        bool isTooMuchSunlight(const bool);
        bool isTooLittleSunlight(const bool);
        bool isSunlight() const;
    };
}

#endif //SOLID_SUNLIGHTSENSOR_H
