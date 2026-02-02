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

    //Struct init
    Config::GridSettings grid;
    AppState state;
    //GridLogic init
    Grid gridLogic(grid.gridCols, grid.gridRows);

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

        float actualWidth = static_cast<float>(gridLogic.getGridWidth()) * cellSize;
        float actualHeight = static_cast<float>(gridLogic.getGridHeight()) * cellSize;

        //Calculate SpecialPoints
        state.startNodeIndex = (gridLogic.getGridHeight() - 1) * gridLogic.getGridWidth();
        state.endNodeIndex = gridLogic.getGridWidth() - 1;

        float offsetX = Config::gridArea.x + ((Config::gridArea.width - actualWidth) / 2.0F);
        float offsetY = Config::gridArea.y + ((Config::gridArea.height - actualHeight) / 2.0F);

        GridTransform transform = {cellSize, offsetX, offsetY};

        UI::setWalls(grid, gridLogic, state, transform);
        UI::drawStartStopPoint(gridLogic, state, transform);
        
    
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginBlendMode(BLEND_ALPHA);

            //Draw actual Grid Borders
            DrawRectangleLinesEx({offsetX, offsetY, actualWidth, actualHeight}, 2.0F , RED);

            //Draw UI Layout
            UI::drawWalls(gridLogic, cellSize, offsetX, offsetY);
            UI::drawMainLayout(customFont, grid, state, cellSize, offsetX, offsetY);

            //GUI Spinner
            if (GuiSpinner(Config::recForSpinnerWidth, nullptr, &grid.gridCols, 10, 100, grid.EditModeWidth) != 0) {
                grid.EditModeWidth = !grid.EditModeWidth; 
            }

            // Höhe-Spinner
            if (GuiSpinner(Config::recForSpinnerHeight, nullptr, &grid.gridRows, 10, 100, grid.EditModeHeight) != 0) {
                grid.EditModeHeight = !grid.EditModeHeight;
            }

            //Synchronization Grid with UI
            if (!grid.EditModeWidth && !grid.EditModeHeight) {
                if (grid.gridCols != gridLogic.getGridWidth() || grid.gridRows != gridLogic.getGridHeight()) {
                    gridLogic.resizeGrid(grid.gridCols, grid.gridRows);
                }
            }

            //Slider /ListView
            GuiSliderBar(Config::recForSlider, "Min", "Max", &state.algorythmSpeed, 1, 100);
            GuiListView(Config::recForListAlgorythm, "A*;Dijkstra;Breadth First search;Depth First search;Right Hand Method;", &state.scrollIndex, &state.activeAlg);

            
        EndDrawing();
    }
    UnloadFont(customFont);
    CloseWindow();
    return 0;
}