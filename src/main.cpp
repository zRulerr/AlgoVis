#include "raylib.h"
#include <vector>
#include <iostream>

int main() {
    // C++17
    std::vector<int> test_version = {1, 2, 3};
    std::cout << "C++ Standard Check: Vektor-Groesse ist " << test_version.size() << std::endl;

    //Window init
    InitWindow(800, 450, "Sui");

    SetTargetFPS(60); 

    //main loop
    while (!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("ANH HANDTUCH KLAU PROGRAMM", 190, 200, 20, LIGHTGRAY);
            DrawCircle(400, 300, 50, MAROON);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}