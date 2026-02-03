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

    //Algo test
    BFS bfs(gridLogic);
    float stepTimer = 0.0f;
    std::vector<int> finalPath; //store final path

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

        //-------------------
        if (state.isRunning && !bfs.isFound()) {
            stepTimer += GetFrameTime();
            float speed = 1.0f / (state.algorythmSpeed + 1.0f); 
            
            if (stepTimer >= speed) {
                bfs.step(state.endNodeIndex);
                stepTimer = 0.0f;
            }
        }

        UI::setWalls(grid, gridLogic, state, transform);
    
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginBlendMode(BLEND_ALPHA);

            //Draw UI Layout
            UI::drawWalls(gridLogic, cellSize, offsetX, offsetY);
            UI::drawBFSState(bfs, gridLogic, transform, state.startNodeIndex, state.endNodeIndex);
            UI::drawStartStopPoint(gridLogic, state, transform);
            UI::drawMainLayout(customFont, grid, state, bfs, gridLogic, cellSize, offsetX, offsetY);
            //Draw actual Grid Borders
            DrawRectangleLinesEx({offsetX, offsetY, actualWidth, actualHeight}, 2.0F , RED);

            //Slider /ListView
            GuiSliderBar(Config::recForSlider, "Min", "Max", &state.algorythmSpeed, 1, 100);
            GuiListView(Config::recForListAlgorythm, "A*;Dijkstra;Breadth First search;Depth First search;Right Hand Method;", &state.scrollIndex, &state.activeAlg);
        EndDrawing();
    }
    UnloadFont(customFont);
    CloseWindow();
    return 0;
}