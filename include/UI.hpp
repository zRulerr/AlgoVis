#pragma once
#include "raylib.h"
#include "Constants.hpp"

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
    auto drawGridLines(Config::GridSettings grid, float cellSize) -> void;

    /** @brief A Method to draw the main GUI Panels */ 
    auto drawMainGuiPanels() -> void;
}