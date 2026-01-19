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
    Config::GridSettings grid;
    
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
    float algorythmSpeed = 10.0f;

    int currentGridSpacing = Config::defaultGridSpacing;

    //main loop
    while (!WindowShouldClose()) {

        float cellSize = UI::CalculateCellSize(grid);
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginBlendMode(BLEND_ALPHA);

            //GUI Elements
            GuiPanel(Config::controlElements, "Rastergröße");
            GuiPanel(Config::settingsElements, "Einstellungen");
            //Spinner (GridWidth)
            if (GuiSpinner(Config::recForSpinnerWidth, nullptr, &grid.gridCols, 10, 100, grid.EditModeWidth)) { //Rasterbreite
                grid.EditModeWidth = !grid.EditModeWidth; //Wechselt den Modus bei Klick
            }
            //Spinner (GridHeight)
            if (GuiSpinner(Config::recForSpinnerHeight, nullptr, &grid.gridRows, 10, 100, grid.EditModeHeight)) { //Rasterbreite
                grid.EditModeHeight = !grid.EditModeHeight; //Wechselt den Modus bei Klick
            }
            GuiSliderBar(Config::recForSlider, "Min", "Max", &algorythmSpeed, 1, 100);
            
            //List for Algorythm selection
            GuiListView(Config::recForListAlgorythm, "A*;Dijkstra;Breadth First search;Depth First search;Right Hand Method;", &scrollIndex, &activeAlg);

            //Sidepanel Header text
            UI::drawAllTexts(customFont);

            for (int i = 0; i <= grid.gridCols ;i++) {
                DrawLineV({Config::gridArea.x + (i * cellSize), Config::gridArea.y},
                        {Config::gridArea.x + (i * cellSize), Config::gridArea.y + (grid.gridRows * cellSize)}, LIGHTGRAY);
            }






            //Seperation lines
            DrawLine(Config::sidePanelWidth, 0, Config::sidePanelWidth, Config::screenHeight, DARKGRAY); // Links
            DrawLine((int)Config::analyticsPanel.x, 0, (int)Config::analyticsPanel.x, Config::screenHeight, DARKGRAY); // Rechts


        EndDrawing();
    }
    UnloadFont(customFont);
    CloseWindow();
    return 0;
}



            // for (int i = 0; i <= grid.gridCols; i++) {
            //     DrawLineV({Config::gridArea.x + (i * cellSize), Config::gridArea.y}, 
            //             {Config::gridArea.x + (i * cellSize), Config::gridArea.y + (grid.gridRows * cellSize)}, 
            //             LIGHTGRAY);
            // }
            // for (int j = 0; j <= grid.gridRows; j++) {
            //     float yPos = Config::gridArea.y + (static_cast<float>(j) * cellSize);
                
            //     Vector2 start = { Config::gridArea.x, yPos };
            //     Vector2 end   = { Config::gridArea.x + (static_cast<float>(grid.gridCols) * cellSize), yPos };
                
            //     DrawLineV(start, end, LIGHTGRAY);
            // }