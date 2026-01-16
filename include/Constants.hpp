#pragma once
#include "raylib.h"

/**
 * @namespace Config
 * @brief Constants used for the Renderer are declared here
 * 
 * This namespace declares Constants used for:
 * -The Dimensions of the Window
 * -Custom Color
 * -Custom Defined Rectangles (for UI Areas, or Panels) 
 */

namespace Config {
    /// @name Window-Dimensions
    /// @{
    inline const int screenWidth = 1600;
    inline const int screenHeight = 900;
    inline const int sidePanelWidth = 300;
    ///@}

    /** @brief Custom Color */
    inline const Color myLightGray = {230, 230, 230, 255};

    /// @name Layout for Rectangles
    /// @{
    inline const Rectangle uiPanel = {0, 0, sidePanelWidth, screenHeight};
    inline const Rectangle gridArea = {sidePanelWidth, 0, screenWidth - (2 * sidePanelWidth), screenHeight};
    inline const Rectangle analyticsPanel = {screenWidth - sidePanelWidth, 0, sidePanelWidth, screenHeight};
    ///@}

    /** @brief Rectangle for inner GUI Elements (Padding) */
    inline const Rectangle controlElements = {10, 100, sidePanelWidth - 20, 200};

    /** */
    inline const int defaultGridSpacing = 40; 

    /** @brief Start point of the Text above the spinner */
    inline const float startX = controlElements.x + 10;
    inline const float startY = controlElements.y + 40;

}