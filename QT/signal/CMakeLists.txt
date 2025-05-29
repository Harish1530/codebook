cmake_minimum_required(VERSION 3.16)

project(signal LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CONFIGURE_DEPENDS ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

file(GLOB_RECURSE SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp"
)

file(GLOB_RECURSE HEADERS
  "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)

add_executable(signal
  ${SOURCES}
  ${HEADERS}
  
)
target_link_libraries(signal
    Qt${QT_VERSION_MAJOR}::Core
)

# Set the include directories
target_include_directories(signal
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(signal Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS signal
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)