cmake_minimum_required(VERSION 3.16)

project(paint_calc LANGUAGES CXX)

# Enable Qt features
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Add the executable
add_executable(paint_calc 
    main.cpp
)

# Link Qt6 libraries
target_link_libraries(paint_calc PRIVATE Qt6::Core Qt6::Widgets)

# Optional: Install target
include(GNUInstallDirs)
install(TARGETS paint_calc
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
