project(caretaker)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCE
        ${PROJECT_SOURCE_DIR}/include/caretaker/WaterDevice.h
        ${PROJECT_SOURCE_DIR}/include/caretaker/WindowDevice.h
        ${PROJECT_SOURCE_DIR}/include/caretaker/AloeCaretaker.h
        ${PROJECT_SOURCE_DIR}/include/caretaker/CactusCaretaker.h
        ${PROJECT_SOURCE_DIR}/src/AloeCaretaker.cpp
        ${PROJECT_SOURCE_DIR}/src/CactusCaretaker.cpp
        )

add_library(${PROJECT_NAME} STATIC ${SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)