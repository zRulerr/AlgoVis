#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "Constants.hpp"
#include "AppState.hpp"
#include "UI.hpp"

#include <vector>
#include <iostream>

/*
--------------TODO List----------------
- Basisfunktionalität Pathfinder Algorithmen implementieren
*/

auto main() -> int {
    //Window init
    InitWindow(static_cast<int>(Config::screenWidth), static_cast<int>(Config::screenHeight), "AlgoVis - Pathfinder v1.0");

    //Grid Settings init
    Config::GridSettings grid;
    AppState state;

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

    int currentGridSpacing = Config::defaultGridSpacing;

    //main loop
    while (!WindowShouldClose()) {

        float cellSize = UI::CalculateCellSize(grid);
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginBlendMode(BLEND_ALPHA);

            //Draw UI Layout
            UI::drawMainLayout(customFont, grid, state, cellSize);

            //Spinner (GridWidth)
            if (GuiSpinner(Config::recForSpinnerWidth, nullptr, &grid.gridCols, 10, 100, grid.EditModeWidth) != 0) { //Rasterbreite
                grid.EditModeWidth = !grid.EditModeWidth; //Wechselt den Modus bei Klick
            }
            //Spinner (GridHeight)
            if (GuiSpinner(Config::recForSpinnerHeight, nullptr, &grid.gridRows, 10, 100, grid.EditModeHeight) != 0) { //Rasterbreite
                grid.EditModeHeight = !grid.EditModeHeight; //Wechselt den Modus bei Klick
            }
            //Slider
            GuiSliderBar(Config::recForSlider, "Min", "Max", &state.algorythmSpeed, 1, 100);
            
            //List for Algorythm selection
            GuiListView(Config::recForListAlgorythm, "A*;Dijkstra;Breadth First search;Depth First search;Right Hand Method;", &state.scrollIndex, &state.activeAlg);

        EndDrawing();
    }
    UnloadFont(customFont);
    CloseWindow();
    return 0;
}