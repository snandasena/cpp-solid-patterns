//
// Created by sajith on 4/20/21.
//

#include <iostream>
#include <mutex>
#include <thread>

#include "sensors/MoistureSensor.h"
#include "sensors/SunlightSensor.h"
#include "caretaker/AloeCaretaker.h"
#include "caretaker/CactusCaretaker.h"

void run()
{
    std::mutex sensorMtx;
    auto sunlightSensor = sensors::SunlightSensor(std::chrono::seconds(2), sensorMtx);
    auto moistureSensor = sensors::MoistureSensor(std::chrono::seconds(2), sensorMtx);

    caretaker::AloeCaretaker aloeCaretaker;
    moistureSensor.subscribe(aloeCaretaker);
    sunlightSensor.subscribe(aloeCaretaker);

    caretaker::CactusCaretaker cactusCaretaker;
    moistureSensor.subscribe(cactusCaretaker);

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