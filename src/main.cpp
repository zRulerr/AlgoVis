#include "raylib.h"
#include <vector>
#include <iostream>

int main() {
    // C++17
    std::vector<int> test_version = {1, 2, 3};
    std::cout << "C++ Standard Check: Vektor-Groesse ist " << test_version.size() << std::endl;

    //Window init
    InitWindow(800, 600, "AlgoVis - Pathfinder v1.0");

    // Nach InitWindow(...)
    Image icon = LoadImage("resources/logo.png");
    SetWindowIcon(icon);
    UnloadImage(icon); //

    SetTargetFPS(60); 

    //main loop
    while (!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}