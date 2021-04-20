cmake_minimum_required(VERSION 3.10)

project(plantcare-better)

SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -O3 -pedantic -Wall -Werror")

add_subdirectory(sensors)
add_subdirectory(caretaker)
add_subdirectory(main)