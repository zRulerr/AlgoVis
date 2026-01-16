#pragma once
#include "raylib.h"

/**
 * @namespace UI
 * @brief Manages the Style of the User Interface
 * 
 * Initializes the Font Style, and the Style of the GUI Elements, for example a Panel
 */

namespace UI {
    /**
     * @brief Initializes a Custom Font from resources/ and return the Font
     */
    auto SetupStyle() -> Font;

    /**
     * @brief Initializes the GUI Elements
     */
    auto SetupGUIElements() -> void;

    /**
     * @brief A Method to draw all texts to the User Interface
     */
    auto drawAllTexts(Font font) -> void;
}