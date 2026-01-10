#Project informations
cmake_minimum_required(VERSION 3.10)
project(AlgorythmVisualizer VERSION 1.0 LANGUAGES CXX)

#Compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#External libraries (Raylib)
add_subdirectory(external/raylib)

#Folder to include to Header files
include_directories(include)

#Setting the Source files
set(SOURCES
    src/main.cpp
)

#Target file
add_executable(AlgoVis ${SOURCES})

#Linker
target_link_libraries(AlgoVis raylib)