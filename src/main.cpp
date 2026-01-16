#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "Constants.hpp"
#include "UI.hpp"

#include <vector>
#include <iostream>


auto main() -> int {

    //Window init
    InitWindow(static_cast<int>(Config::screenWidth), static_cast<int>(Config::screenHeight), "AlgoVis - Pathfinder v1.0");
    
    Image icon = LoadImage("resources/logo.png");
    SetWindowIcon(icon);
    UnloadImage(icon); 

    SetTargetFPS(60); 

    //Global Style setting for GUI Elements
    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, ColorToInt(Config::myLightGray));
    GuiSetStyle(DEFAULT, BORDER_COLOR_NORMAL, ColorToInt(LIGHTGRAY));
    GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, ColorToInt(BLACK));

    Font customFont = UI::SetupStyle();
    

    //main loop
    while (!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(RAYWHITE);

            //Background for the Side Panels
            // DrawRectangleRec(uiPanel, LIGHTGRAY);
            // DrawRectangleRec(analyticsPanel, ColorAlpha(LIGHTGRAY, 0.5f)); 

            //Seperation lines
            DrawLine(Config::sidePanelWidth, 0, Config::sidePanelWidth, Config::screenHeight, DARKGRAY); // Links
            DrawLine((int)Config::analyticsPanel.x, 0, (int)Config::analyticsPanel.x, Config::screenHeight, DARKGRAY); // Rechts

            //GUI Elements
            GuiPanel(Config::controlElements, "Rastergröße");

            //Sidepanel Header text
            DrawTextEx(customFont, "STEUERUNG", {20, 20}, 22, 2, BLACK);
            DrawTextEx(customFont, "ANALYTICS", {Config::analyticsPanel.x + 20, 20}, 22, 2, BLACK);

            //Test Button 
            // if (GuiButton((Rectangle){ 20, 100, 210, 40 }, "Algorithmus Starten")) {
            // std::cout << "Start-Button gedrueckt!" << std::endl;
            // }
        EndDrawing();
    }
    UnloadFont(customFont);
    CloseWindow();
    return 0;
}