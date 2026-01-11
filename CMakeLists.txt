#Project informations
cmake_minimum_required(VERSION 3.10)
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

#Source files (automatic inclusion)
file(GLOB_RECURSE SOURCES "src/*.cpp")

#Target file
add_executable(AlgoVis ${SOURCES})

#Folder to include to Header files
target_include_directories(AlgoVis PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/core
)

#Linker
target_link_libraries(AlgoVis raylib)