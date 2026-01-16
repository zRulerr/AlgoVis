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

    Font customFont = UI::SetupStyle();
    UI::SetupGUIElements();

    int currentGridSpacing = Config::defaultGridSpacing;
    bool spinnerEditMode = false;
    Rectangle spinnerRec = {Config::startX, Config::startY + 25, 120, 30 };

    //main loop
    while (!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(RAYWHITE);

            //Seperation lines
            DrawLine(Config::sidePanelWidth, 0, Config::sidePanelWidth, Config::screenHeight, DARKGRAY); // Links
            DrawLine((int)Config::analyticsPanel.x, 0, (int)Config::analyticsPanel.x, Config::screenHeight, DARKGRAY); // Rechts

            //GUI Elements
            GuiPanel(Config::controlElements, "Rastergröße");
            if (GuiSpinner(spinnerRec, nullptr, &currentGridSpacing, 10, 100, spinnerEditMode)) { //Rasterbreite
                spinnerEditMode = !spinnerEditMode; //Wechselt den Modus bei Klick
            }
            

            //Sidepanel Header text
            DrawTextEx(customFont, "STEUERUNG", {20, 20}, 22, 2, BLACK);
            DrawTextEx(customFont, "ANALYTICS", {Config::analyticsPanel.x + 20, 20}, 22, 2, BLACK);
            DrawTextEx(customFont, "RASTERBREITE", {Config::startX, Config::startY}, 18, 1, DARKGRAY); //Spinnertext


        EndDrawing();
    }
    UnloadFont(customFont);
    CloseWindow();
    return 0;
}