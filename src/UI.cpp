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
        DrawTextEx(font, "STEUERUNG", {20, 20}, 24, 2, BLACK);
        DrawTextEx(font, "ANALYTICS", {Config::analyticsPanel.x + 20, 20}, 24, 2, BLACK);
        DrawTextEx(font, "Rasterbreite", {Config::startX, Config::startY}, 16, 1, BLACK); //Spinnertext
        DrawTextEx(font, "Rasterhöhe", {Config::startX, Config::startY + 60}, 16, 1, BLACK); //Spinnertext
    }

    auto CalculateCellSize(const Config::GridSettings& grid) -> float {
        //Check division 
        if (grid.gridCols <= 0 || grid.gridRows <= 0) return 0.0f;

        float cellSizeX = Config::gridArea.width / grid.gridCols;
        float cellSizeY = Config::gridArea.height / grid.gridRows;

        //Return the smaller Cellsize to get quadratic Cells
        return (cellSizeX < cellSizeY) ? cellSizeX : cellSizeY;
    }

    auto drawGridLines(Config::GridSettings grid, float cellSize) -> void {
        //Draw vertical Lines
        for (int i = 0; i <= grid.gridCols ;i++) {
            DrawLineV({Config::gridArea.x + (i * cellSize), Config::gridArea.y},
                    {Config::gridArea.x + (i * cellSize), Config::gridArea.y + (grid.gridRows * cellSize)}, LIGHTGRAY);
        }

        //Use same Logic to draw horizontal Lines, by rotating the coordinates
        for (int i = 0; i <= grid.gridRows ;i++) {
            DrawLineV({Config::gridArea.x, Config::gridArea.y + (i * cellSize)},
                    {Config::gridArea.x + (grid.gridCols * cellSize), Config::gridArea.y + (i * cellSize)}, LIGHTGRAY);
        }
    }

    auto drawMainGuiPanels() -> void {
        GuiPanel(Config::controlElements, "Rastergröße");
        GuiPanel(Config::settingsElements, "Einstellungen");
        GuiPanel(Config::playbackElements, "Playback Controls");
    }

    auto drawSeperationLines() -> void {
        //Seperation lines
        DrawLine(Config::sidePanelWidth, 0, Config::sidePanelWidth, Config::screenHeight, DARKGRAY); // Links
        DrawLine((int)Config::analyticsPanel.x, 0, (int)Config::analyticsPanel.x, Config::screenHeight, DARKGRAY); // Rechts
    }

    auto drawMainLayout(Font customFont, const Config::GridSettings& grid, float cellSize) -> void {
        //Draw Main GUI Panels
        drawMainGuiPanels();

        //Sidepanel Header text
        drawAllTexts(customFont);

        //Grid Drawing
        drawGridLines(grid, cellSize);

        //Seperation Lines drawing
        drawSeperationLines();
    }
}