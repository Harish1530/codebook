cmake_minimum_required(VERSION 3.16)

project(quickProject1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appquickProject1
    main.cpp
)

qt_add_qml_module(appquickProject1
    URI quickProject1
    QML_FILES
        Main.qml
        FuelGauge.qml
        Indicators.qml
        RPMGauge.qml
        Speedometer.qml
        QML_FILES Practice.qml

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appquickProject1 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appquickProject1
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appquickProject1
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appquickProject1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
