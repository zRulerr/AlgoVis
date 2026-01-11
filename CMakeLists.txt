#Project informations
cmake_minimum_required(VERSION 3.10)
project(AlgorythmVisualizer VERSION 1.0 LANGUAGES CXX)

#Compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#External libraries (Raylib)
add_subdirectory(external/raylib)

#Folder to include to Header files
include_directories(include include/core)

#Source files (automatic inclusion)
file(GLOB_RECURSE SOURCES "src/*.cpp")

#Target file
add_executable(AlgoVis ${SOURCES})

#Linker
target_link_libraries(AlgoVis raylib)

#Search for Clang-Tidy
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")

if(CLANG_TIDY_EXE)
    message(STATUS "Clang-Tidy found: ${CLANG_TIDY_EXE}")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
else()
    message(STATUS "Clang-Tidy not found.")
endif()