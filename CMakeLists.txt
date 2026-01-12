#Project informations
cmake_minimum_required(VERSION 3.14)
project(AlgorythmVisualizer VERSION 1.0 LANGUAGES CXX)

#Compiler settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Search for Clang-Tidy
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    message(STATUS "Clang-Tidy found: ${CLANG_TIDY_EXE}")
    set(CMAKE_CXX_CLANG_TIDY 
        "${CLANG_TIDY_EXE}"
        "--config-file=${CMAKE_CURRENT_SOURCE_DIR}/.clang-tidy"
        "--extra-arg=--target=x86_64-w64-windows-gnu" # Hilft Clang, MinGW zu verstehen
    )
endif()

#External libraries (Raylib)
add_subdirectory(external/raylib)

#Catch2 for testing (FetchContent)
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 
)
FetchContent_MakeAvailable(Catch2)

#Source files (automatic inclusion)
file(GLOB_RECURSE LIB_SOURCES "src/core/*.cpp")

add_library(AlgoVisCore ${LIB_SOURCES})

#Target file
add_executable(AlgoVis src/main.cpp)
target_link_libraries(AlgoVis PRIVATE AlgoVisCore raylib)

#Folder to include to Header files
target_include_directories(AlgoVisCore PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/core
)

#Catch2 Unit Tests
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/GridTests.cpp")
    add_executable(UnitTests tests/GridTests.cpp)
    target_link_libraries(UnitTests PRIVATE AlgoVisCore Catch2::Catch2WithMain)
endif()