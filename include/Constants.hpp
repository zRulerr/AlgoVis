#pragma once
#include "raylib.h"

namespace Config {
    //Dimensions
    inline const int screenWidth = 1600;
    inline const int screenHeight = 900;
    inline const int sidePanelWidth = 300;

    //Custom Color
    inline const Color myLightGray = {230, 230, 230, 255};

    //Rectangle sizes for the 3 sections, UIPanel, GridArea and AnalyticsPanel
    inline Rectangle uiPanel = {0, 0, sidePanelWidth, screenHeight};
    inline Rectangle gridArea = {sidePanelWidth, 0, screenWidth - (2 * sidePanelWidth), screenHeight};
    inline Rectangle analyticsPanel = {screenWidth - sidePanelWidth, 0, sidePanelWidth, screenHeight};

    //Rectangle for inner GUI Elements (Padding)
    inline Rectangle controlElements = {10, 100, sidePanelWidth - 20, 200};
}