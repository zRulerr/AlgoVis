#include "raylib.h"
#include <vector>
#include <iostream>

int main() {
    // Test: C++17 Feature (Structured Bindings / Initializer)
    // Wenn das kompiliert, funktioniert dein C++17 Standard!
    std::vector<int> test_version = {1, 2, 3};
    std::cout << "C++ Standard Check: Vektor-Groesse ist " << test_version.size() << std::endl;

    // Fenster initialisieren (Breite, Höhe, Titel)
    InitWindow(800, 450, "CMake + Raylib Test");

    SetTargetFPS(60); // 60 Bilder pro Sekunde

    // Hauptschleife
    while (!WindowShouldClose()) {
        // 1. Update (Logik hier)
        
        // 2. Zeichnen
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Glückwunsch! Raylib & CMake laufen.", 190, 200, 20, LIGHTGRAY);
            DrawCircle(400, 300, 50, MAROON);
        EndDrawing();
    }

    CloseWindow(); // Ressourcen freigeben
    return 0;
}