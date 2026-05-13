#pragma once
#include "raylib.h"
#include <array>
#include "Constants.hpp"
#include "AppState.hpp"
#include "Node.hpp"
#include "Grid.hpp"
#include "BFS.hpp"

/**
 * @struct GridTransform
 * @brief Variables that transform the grid are stored here
 */

struct GridTransform {
    float cellSize;
    float offsetX;
    float offsetY;
};

/**
 * @namespace UI
 * @brief Manages the Style of the User Interface
 * 
 * Initializes the Font Style, and the Style of the GUI Elements, for example a Panel
 */

namespace UI {
    /** @brief Initializes a Custom Font from resources/ and return the Font */
    auto SetupStyle() -> Font;

    /**
     * @brief Initializes the GUI Elements
     */
    auto SetupGUIElements() -> void;

    /**
     * @brief A Method to draw all texts to the User Interface
     */
    auto drawAllTexts(Font font) -> void;

    /** @brief A Method to calculate the CellSize */
    auto CalculateCellSize(const Config::GridSettings& grid) -> float;

    /** @brief A Method to draw the vertical Lines of the Grid */
    auto drawGridVerticalLines(Config::GridSettings grid, float cellSize) -> void;

    /** @brief A Method to draw the horizontal Lines of the Grid */
    auto drawGridLines(const Config::GridSettings grid, float cellSize, float offsetX, float offsetY) -> void;

    /** @brief A Method to draw GUI Buttons and Checkboxes */
    auto drawGUIButtons (AppState &state, BFS &bfs) -> void;

    /** @brief A Method to draw the main GUI Panels */ 
    auto drawMainGuiPanels() -> void;

    /** @brief A Method to draw lines seperating the AnaylticsUI, grid, and SettingUI */
    auto drawSeperationLines() -> void;

    /** @brief Draws the Main Layout */
    auto drawMainLayout(Font customFont, Config::GridSettings& grid, AppState& state, BFS& bfs, Grid& gridLogic, float cellSize, float offsetX, float offsetY) -> void;

    /** @brief A Method to set Walls inside the grid, which will be drawn by a following Method */
    auto setWalls(const Config::GridSettings& grid, Grid& gridLogic, AppState& state, GridTransform transform) -> void;

    /** @brief A Method to draw black Walls with Left Mouse button click */
    auto drawWalls(const Grid& gridLogic, float cellSize, float offsetX, float offsetY) -> void;

    /** @brief A Method to draw the Start (green) and the end point (red) of the Grid /Maze */
    auto drawStartStopPoint(const Grid& gridLogic, AppState& state, GridTransform transform) -> void;

    /** @brief A Method to draw the BFS state (visited nodes and path) */
    auto drawBFSState(const BFS& bfs, const Grid& gridLogic, GridTransform transform, int startIndex, int endIndex) -> void;

    /** @brief A Method to draw the Grid Controls such as Spinners for grid dimensions */
    auto drawGridControls(Config::GridSettings& grid, Grid& gridLogic) -> void;
}