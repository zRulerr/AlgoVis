#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

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

    //Custom Font init
    Font customFont = LoadFont("resources/Inter_24pt-Regular.ttf");
    GuiSetFont(customFont);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 24);
    
    Image icon = LoadImage("resources/logo.png");
    SetWindowIcon(icon);
    UnloadImage(icon); 

    SetTargetFPS(60); 

    //main loop
    while (!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(RAYWHITE);

            //Background for the Side Panels
            DrawRectangleRec(uiPanel, LIGHTGRAY);
            DrawRectangleRec(analyticsPanel, ColorAlpha(LIGHTGRAY, 0.5f)); 

            //Seperation lines
            DrawLine(sidePanelWidth, 0, sidePanelWidth, screenHeight, DARKGRAY); // Links
            DrawLine(analyticsPanel.x, 0, analyticsPanel.x, screenHeight, DARKGRAY); // Rechts

            //Sidepanel Header text
            DrawTextEx(customFont, "STEUERUNG", { 20, 20 }, 22, 2, BLACK);
            DrawTextEx(customFont, "ANALYTICS", { analyticsPanel.x + 20, 20 }, 22, 2, BLACK);

            //Test Buttin 
            if (GuiButton((Rectangle){ 20, 100, 210, 40 }, "Algorithmus Starten")) {
            std::cout << "Start-Button gedrueckt!" << std::endl;
            }
        EndDrawing();
    }
    UnloadFont(customFont);
    CloseWindow();
    return 0;
}