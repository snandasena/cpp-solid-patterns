//
// Created by sajith on 3/25/21.
//

#ifndef SOLID_MOISTURESENSOR_H
#define SOLID_MOISTURESENSOR_H

#include <chrono>
#include <mutex>
#include <set>

#include "caretaker/PlantCaretaker.h"

namespace sensors
{
    class MoistureSensor
    {
        const std::chrono::seconds sleepTime;
        std::mutex &mtx;
        std::set<caretaker::PlantCareTaker *> careTakers;

        const int min = 0;
        const int max = 10;
        const int threshold = 3;

    public:
        MoistureSensor(const std::chrono::seconds, std::mutex &mtx);
        void subscribe(caretaker::PlantCareTaker &);
        void operator()();

    private:
        bool isAirTooDry();
        bool isSoilTooDry();
        int getAirMoisture();
        int getSoilMoisture();
    };
}


#endif //SOLID_MOISTURESENSOR_H
