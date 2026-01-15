#include "raylib.h"
#include <vector>
#include <iostream>

const int screenWidth = 1280;
const int screenHeight = 720;
const int sidePanelWidth = 250;

Rectangle uiPanel = { 0, 0, sidePanelWidth, screenHeight };
Rectangle gridArea = { sidePanelWidth, 0, screenWidth - (2 * sidePanelWidth), screenHeight };
Rectangle analyticsPanel = { screenWidth - sidePanelWidth, 0, sidePanelWidth, screenHeight };

int main() {
    // C++17
    std::vector<int> test_version = {1, 2, 3};
    std::cout << "C++ Standard Check: Vektor-Groesse ist " << test_version.size() << std::endl;

    //Window init
    InitWindow(screenWidth, screenHeight, "AlgoVis - Pathfinder v1.0");

    Image icon = LoadImage("resources/logo.png");
    SetWindowIcon(icon);
    UnloadImage(icon); //

    SetTargetFPS(60); 

    //main loop
    while (!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();

        //User Interface Panel (Left)
        DrawRectangleRec(uiPanel, LIGHTGRAY);
        DrawLine(sidePanelWidth, 0, sidePanelWidth, screenHeight, DARKGRAY); // Trennlinie
        DrawText("STEUERUNG", 20, 20, 20, DARKGRAY);

        //Analytics Panel (Right)
        DrawRectangleRec(analyticsPanel, ColorAlpha(LIGHTGRAY, 0.5f)); 
        DrawLine(analyticsPanel.x, 0, analyticsPanel.x, screenHeight, DARKGRAY); // Trennlinie
        DrawText("ANALYTICS", analyticsPanel.x + 20, 20, 20, DARKGRAY);
    }

    CloseWindow();
    return 0;
}