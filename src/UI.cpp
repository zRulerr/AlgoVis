#include "UI.hpp"
#include "raygui.h"
#include "Constants.hpp"

namespace UI {
        auto SetupStyle() -> Font {
        
        //Load "UI-Style"
        GuiLoadStyle("resources/style_bluish.rgs");
        //Custom Font init
        Font customFont = LoadFontEx("resources/Roboto-Regular.ttf", 96, nullptr, 250);
        SetTextureFilter(customFont.texture, TEXTURE_FILTER_BILINEAR);
        GenTextureMipmaps(&customFont.texture);

        GuiSetFont(customFont);
        GuiSetStyle(DEFAULT, TEXT_SIZE, 16);
        

        return customFont;
    }

    auto SetupGUIElements() -> void {
        //Global Style setting for GUI Elements
        GuiSetStyle(DEFAULT, BACKGROUND_COLOR, ColorToInt(Config::myLightGray));
        GuiSetStyle(DEFAULT, BORDER_COLOR_NORMAL, ColorToInt(GRAY));
        GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, ColorToInt(BLACK));

        // Make listview scrollbar a bit wider so it's easier to see/click
        GuiSetStyle(LISTVIEW, SCROLLBAR_WIDTH, 12);
    }

    auto drawAllTexts(Font font) -> void {
        DrawTextEx(font, "CONTROLS", {20, 20}, 24, 2, BLACK);
        DrawTextEx(font, "ANALYTICS", {Config::analyticsPanel.x + 20, 20}, 24, 2, BLACK);
        DrawTextEx(font, "Gridwidth", {Config::startX, Config::startY}, 16, 1, BLACK); //Spinnertext
        DrawTextEx(font, "Gridheight", {Config::startX, Config::startY + 60}, 16, 1, BLACK); //Spinnertext
        DrawTextEx(font, "Animation speed", {Config::settingsElements.x + 10, Config::settingsElements.y + 30}, 16, 1, BLACK);
        DrawTextEx(font, "Draw Walls (toggle)", {Config::settingsElements.x + 10, Config::settingsElements.y + 85}, 16, 1, BLACK);
    }

    auto CalculateCellSize(const Config::GridSettings& grid) -> float {
        //Check division 
        if (grid.gridCols <= 0 || grid.gridRows <= 0) return 0.0F;

        float cellSizeX = Config::gridArea.width / static_cast<float>(grid.gridCols);
        float cellSizeY = Config::gridArea.height / static_cast<float>(grid.gridRows);

        //Return the smaller Cellsize to get quadratic Cells
        return (cellSizeX < cellSizeY) ? cellSizeX : cellSizeY;
    }

    auto drawGridLines(const Config::GridSettings grid, float cellSize) -> void {
        //Draw vertical Lines
        for (int i = 0; i <= grid.gridCols; i++) {
            float xOffset = static_cast<float>(i) * cellSize; //cast i to a float since cellSize is also a float
            DrawLineV(
                {Config::gridArea.x + xOffset, Config::gridArea.y},
                {Config::gridArea.x + xOffset, Config::gridArea.y + (static_cast<float>(grid.gridRows) * cellSize) },
                LIGHTGRAY
            );
        }
        //Horizontal Lines
        for (int j = 0; j <= grid.gridRows; j++) {
            float yOffset = static_cast<float>(j) * cellSize; //cast j to a float since cellSize is also a float
            DrawLineV(
                {Config::gridArea.x, Config::gridArea.y + yOffset},
                {Config::gridArea.x + (static_cast<float>(grid.gridCols) * cellSize), Config::gridArea.y + yOffset},
                LIGHTGRAY
            );
        }
    }

    auto drawMainGuiPanels() -> void {
        GuiPanel(Config::controlElements, "Grid Dimensions");
        GuiPanel(Config::settingsElements, "Settings");
        GuiPanel(Config::playbackElements, "Playback Controls");
    }

    auto drawGUIButtons () -> void {
        if (GuiButton(Config::recForStartStopButton, "Start | Stop") != 0) {
            TraceLog(LOG_INFO, "Button \"Start /Stop\" has been pressed!");
        }

        //if (GuiCheckBox(Config::recForDrawWallCheckbox, "Wall", s) != 0) {

        }
    }

    auto drawSeperationLines() -> void {
        //Seperation lines
        DrawLine(Config::sidePanelWidth, 0, Config::sidePanelWidth, Config::screenHeight, DARKGRAY); // Links
        DrawLine((int)Config::analyticsPanel.x, 0, (int)Config::analyticsPanel.x, Config::screenHeight, DARKGRAY); // Rechts
    }

    auto drawMainLayout(Font customFont, const Config::GridSettings& grid, float cellSize) -> void {
        //Grid Drawing
        drawGridLines(grid, cellSize);
        
        //Draw Main GUI Panels
        drawMainGuiPanels();

        //Draw Elements like buttons or lists etc.
        drawGUIButtons();

        //Sidepanel Header text
        drawAllTexts(customFont);

        //Seperation Lines drawing
        drawSeperationLines();
    }
}