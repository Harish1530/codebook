cmake_minimum_required(VERSION 3.14)
 
project(digital-instrument-cluster)
 
set(CMAKE_CXX_STANDARD 17)
 
set(CMAKE_AUTOMOC ON)
find_package(Qt6 COMPONENTS Core Gui Qml Quick REQUIRED)
 
# Automatically collect all .cpp files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)
 
# Automatically collect all .h files
file(GLOB_RECURSE HEADERS
    src/*.h
)
 
# Automatically collect all .qml files
file(GLOB_RECURSE QML_FILES
    src/qml/*.qml
)
 
add_executable(digital-instrument-cluster
    ${SOURCES}
    ${HEADERS}
)
 
target_link_libraries(digital-instrument-cluster
    PRIVATE
        Qt6::Core
        Qt6::Qml
        Qt6::Quick
)

qt6_add_qml_module(digital-instrument-cluster
    URI com.digitalinstrumentcluster
    VERSION 1.0
    QML_FILES
        src/qml/main.qml
        src/qml/FuelGauge.qml
        src/qml/Speedometer.qml
        src/qml/RPMGauge.qml
        src/qml/Indicators.qml
)

set_target_properties(digital-instrument-cluster PROPERTIES
    QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/qml"
)