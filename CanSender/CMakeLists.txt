cmake_minimum_required(VERSION 3.21)
project(CanSender VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    SerialBus
)

qt_standard_project_setup()

add_executable(CanSender
    main.cpp
    cansender.h cansender.cpp
)

target_link_libraries(CanSender
    PRIVATE
        Qt6::Core
        Qt6::SerialBus
)

set_target_properties(CanSender PROPERTIES
   WIN32_EXECUTABLE FALSE
)
