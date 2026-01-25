#pragma once
#include "raylib.h"
#include "Constants.hpp"
#include "AppState.hpp"
#include "Node.hpp"
#include "Grid.hpp"

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
    auto drawGUIButtons (AppState &state) -> void;

    /** @brief A Method to draw the main GUI Panels */ 
    auto drawMainGuiPanels() -> void;

    /** @brief A Method to draw lines seperating the AnaylticsUI, grid, and SettingUI */
    auto drawSeperationLines() -> void;

    /** @brief Draws the Main Layout */
    auto drawMainLayout(Font customFont, const Config::GridSettings& grid, AppState& state, float cellSize, float offsetX, float offsetY) -> void;

    /** @brief A Method to set Walls inside the grid, which will be drawn by a following Method */
    auto setWalls(const Config::GridSettings& grid, float cellSize, Grid& gridLogic, AppState& state, float offsetX, float offsetY) -> void;

    /** @brief A Method to draw black Walls with Left Mouse button click */
    auto drawWalls(const Grid& gridLogic, float cellSize, float offsetX, float offsetY) -> void;

    /** @brief A Method to draw the Start (green) and the end point (red) of the Grid /Maze */
    auto drawStartStopPoint(const Grid& gridLogic, float cellSize, float offsetX, float offsetY, int startIdx, int endIdx) -> void;
}