project(sensors)

set(SOURCE
        ${PROJECT_SOURCE_DIR}/include/sensors/SunlightSensor.h
        ${PROJECT_SOURCE_DIR}/include/sensors/MoistureSensor.h
        ${PROJECT_SOURCE_DIR}/src/SunlightSensor.cpp
        ${PROJECT_SOURCE_DIR}/src/MoistureSensor.cpp)


add_library(${PROJECT_NAME} STATIC ${SOURCE})