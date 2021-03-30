//
// Created by sajith on 3/25/21.
//
#include <thread>
#include <mutex>

#include "caretaker/PlantCaretaker.h"
#include "sensors/MoistureSensor.h"
#include "sensors/SunlightSensor.h"

void run()
{
    std::mutex sensorMutex;
    auto sunlightSensor = sensors::SunlightSensor(std::chrono::seconds(2), sensorMutex);
    auto moistureSensor = sensors::MoistureSensor(std::chrono::seconds(3), sensorMutex);

    caretaker::PlantCareTaker plantCareTaker1;
    moistureSensor.subscribe(plantCareTaker1);
    sunlightSensor.subcribe(plantCareTaker1);

    caretaker::PlantCareTaker plantCareTaker2;
    moistureSensor.subscribe(plantCareTaker2);
    sunlightSensor.subcribe(plantCareTaker2);

    std::thread sunlightSensorThread(sunlightSensor);
    std::thread moistureSensorThread(moistureSensor);

    sunlightSensorThread.join();
    moistureSensorThread.join();
}

int main()
{

    run();
    return 0;

}