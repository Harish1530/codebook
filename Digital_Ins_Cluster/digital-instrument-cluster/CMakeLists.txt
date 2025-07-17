cmake_minimum_required(VERSION 3.14)
 
project(digital-instrument-cluster)
 
set(CMAKE_CXX_STANDARD 17)
 
find_package(Qt6 REQUIRED COMPONENTS Core Qml Quick)
 
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
    ${QML_FILES}
)
 
target_link_libraries(digital-instrument-cluster
    Qt6::Core
    Qt6::Qml
    Qt6::Quick
)
 
set_target_properties(digital-instrument-cluster PROPERTIES
    QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/qml"
)