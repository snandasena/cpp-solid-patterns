//
// Created by sajith on 3/25/21.
//

#ifndef SOLID_SUNLIGHTSENSOR_H
#define SOLID_SUNLIGHTSENSOR_H

#include <chrono>
#include <mutex>
#include <optional>
#include <set>

#include "caretaker/PlantCaretaker.h"

namespace sensors
{
    class SunlightSensor
    {
        using TimePoint = decltype(std::chrono::system_clock::now());

        const std::chrono::seconds sleepTime;
        std::mutex &mtx;
        std::set<caretaker::PlantCareTaker *> caretakers;

        std::optional<TimePoint> sunlightOnFrom;
        std::optional<TimePoint> sunlightOffFrom;

        const int threshold = 2;
        bool sensorOn = true;

    public:
        SunlightSensor(const std::chrono::seconds, std::mutex &);
        void subcribe(caretaker::PlantCareTaker &);
        void operator()();

    private:

        void updateState(const bool);
        bool isTooMuchSunlight(const bool);
        bool isTooLittleSunlight(const bool);
        bool isSunlight() const;

    };
}// namespace sensors

#endif //SOLID_SUNLIGHTSENSOR_H
