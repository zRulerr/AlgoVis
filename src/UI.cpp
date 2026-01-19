#include "UI.hpp"
#include "raygui.h"
#include "Constants.hpp"
#include "Shaders.hpp"

Shader sdfShader = LoadShaderFromMemory(nullptr, sdfShaderCode);

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
}