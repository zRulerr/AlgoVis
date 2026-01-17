#pragma once
#include "raylib.h"
#include <string>

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

    inline const int vertikalGap = 10;

    /// @name Window-Dimensions
    /// @{
    inline const int screenWidth = 1600;
    inline const int screenHeight = 900;
    inline const int sidePanelWidth = 300;
    ///@}

    /** @brief Custom Color */
    inline const Color myLightGray = {230, 230, 230, 255};
    
    /** @brief Rectangle for inner GUI Elements (Padding) */
    inline const Rectangle controlElements = {10, 50, sidePanelWidth - 20, 180};
    inline const Rectangle settingsElements = {10, 390, sidePanelWidth - 20, 200};

    /// @name Layout for Rectangles
    /// @{
    inline const Rectangle uiPanel = {0, 0, sidePanelWidth, screenHeight};
    inline const Rectangle gridArea = {sidePanelWidth, 0, screenWidth - (2 * sidePanelWidth), screenHeight};
    inline const Rectangle analyticsPanel = {screenWidth - sidePanelWidth, 0, sidePanelWidth, screenHeight};
    ///@}
    
    /** @brief Start point of the Text above the spinner */
    inline const float startX = controlElements.x + 10;
    inline const float startY = controlElements.y + 40;

    /** */
    inline const Rectangle recForSpinnerWidth = {startX, startY + 25, sidePanelWidth - 40, 20 };
    inline const Rectangle recForSpinnerHeight = {startX, startY + 85, sidePanelWidth - 40, 20 };

    /** */
    inline const Rectangle recForListAlgorythm = {10, controlElements.y + 180 + vertikalGap, sidePanelWidth - 20, 140};
    inline const Rectangle recForSlider = {50,  recForSpinnerHeight.y + controlElements.height + vertikalGap + 60, sidePanelWidth - 90, 20};

    /** @brief The Grid Spacing is the amount of Space between each Cell/Node in pixel */
    inline const int defaultGridSpacing = 40; 

    /** @brief Struct to load and change the Setting of the Grid  */
    struct GridSettings {
        int gridCols = 20;
        int gridRows = 20;
        bool EditModeWidth = false;
        bool EditModeHeight = false;  
    };
}