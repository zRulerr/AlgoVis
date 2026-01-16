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
    
    //Icon setup
    Image icon = LoadImage("resources/logo.png");
    SetWindowIcon(icon);
    UnloadImage(icon); 

    //Screen refresh rate
    SetTargetFPS(60); 

    //Custom Font is initialized here
    Font customFont = UI::SetupStyle();

    //GUI Elements are setup here
    UI::SetupGUIElements();

    //Variables needed for ListView, refactor ?
    int scrollIndex = 0;
    int activeAlg = 0;
    bool listViewEditMode = false;

    //
    bool spinnerEditMode = false;     
    int currentGridSpacing = Config::defaultGridSpacing;

    //main loop
    while (!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(RAYWHITE);

            //Seperation lines
            DrawLine(Config::sidePanelWidth, 0, Config::sidePanelWidth, Config::screenHeight, DARKGRAY); // Links
            DrawLine((int)Config::analyticsPanel.x, 0, (int)Config::analyticsPanel.x, Config::screenHeight, DARKGRAY); // Rechts

            //GUI Elements
            GuiPanel(Config::controlElements, "Rastergröße");
            //Spinner (GridWidth)
            if (GuiSpinner(Config::recForSpinnerWidth, nullptr, &currentGridSpacing, 10, 100, spinnerEditMode)) { //Rasterbreite
                spinnerEditMode = !spinnerEditMode; //Wechselt den Modus bei Klick
            }
            //Spinner (GridHeight)
            if (GuiSpinner(Config::recForSpinnerHeight, nullptr, &currentGridSpacing, 10, 100, spinnerEditMode)) { //Rasterbreite
                spinnerEditMode = !spinnerEditMode; //Wechselt den Modus bei Klick
            }
            
            //List for Algorythm selection
            GuiListView(Config::recForListAlgorythm, "A*;Dijksta;Breadth First search;Depth First search;Right Hand Method;", &scrollIndex, &activeAlg);

            //Sidepanel Header text
            UI::drawAllTexts(customFont);


        EndDrawing();
    }
    UnloadFont(customFont);
    CloseWindow();
    return 0;
}