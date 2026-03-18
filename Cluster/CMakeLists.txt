cmake_minimum_required(VERSION 3.21)

project(Cluster VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Load Qt modules first (this defines Qt CMake commands)
find_package(Qt6 6.2 REQUIRED COMPONENTS
    Quick
    Qml
    QuickControls2
    SerialBus
)

# ---- Put policy here (after find_package) and guard it ----
if (COMMAND qt_policy)
    qt_policy(SET QTP0001 NEW)   # silence the “QTP0001 is not set” warning
endif()

qt_standard_project_setup()

add_executable(Cluster
    main.cpp
    clustercontroller.h
    clustercontroller.cpp
    canbusmanager.h
    canbusmanager.cpp
)

qt_add_qml_module(Cluster
    URI Cluster
    VERSION 1.0
    QML_FILES
        Main.qml
        Speedometer.qml
        RPMGauge.qml
        FuelGauge.qml
        EngineTemp.qml   # <-- keep only if this file exists at your -S source path
        Trip.qml
        Odometer.qml
        Indicators.qml
        GearColumn.qml
)

target_link_libraries(Cluster
    PRIVATE
        Qt6::Quick
        Qt6::Qml
        Qt6::QuickControls2
        Qt6::SerialBus
)

set_target_properties(Cluster PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Cluster
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
