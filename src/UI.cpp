#include "UI.hpp"
#include "raygui.h"
#include "Constants.hpp"

namespace UI {
        auto SetupStyle() -> Font {
        //Custom Font init
        Font customFont = LoadFontEx("resources/Inter_24pt-Regular.ttf", 96, nullptr, 250);
        SetTextureFilter(customFont.texture, TEXTURE_FILTER_BILINEAR);

        GuiSetFont(customFont);
        GuiSetStyle(DEFAULT, TEXT_SIZE, 18);

        return customFont;
    }

    auto SetupGUIElements() -> void {
        //Global Style setting for GUI Elements
        GuiSetStyle(DEFAULT, BACKGROUND_COLOR, ColorToInt(Config::myLightGray));
        GuiSetStyle(DEFAULT, BORDER_COLOR_NORMAL, ColorToInt(LIGHTGRAY));
        GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, ColorToInt(BLACK));
        // Make scrollbars visible even when not hovered: give them a distinct base and border color
        GuiSetStyle(SCROLLBAR, BASE_COLOR_NORMAL, ColorToInt(LIGHTGRAY));      // track color
        GuiSetStyle(SCROLLBAR, BORDER_COLOR_NORMAL, ColorToInt(GRAY));         // track border
        GuiSetStyle(SCROLLBAR, BASE_COLOR_FOCUSED, ColorToInt(SKYBLUE));      // hover color (keep default-ish behavior)
        GuiSetStyle(SCROLLBAR, BASE_COLOR_PRESSED, ColorToInt(DARKGRAY));     // pressed color

        // Make listview scrollbar a bit wider so it's easier to see/click
        GuiSetStyle(LISTVIEW, SCROLLBAR_WIDTH, 12);

    }

    auto drawAllTexts(Font font) -> void {
        DrawTextEx(font, "STEUERUNG", {20, 20}, 22, 2, BLACK);
        DrawTextEx(font, "ANALYTICS", {Config::analyticsPanel.x + 20, 20}, 22, 2, BLACK);
        DrawTextEx(font, "RASTERBREITE", {Config::startX, Config::startY}, 18, 1, DARKGRAY); //Spinnertext
        DrawTextEx(font, "RASTERHÖHE", {Config::startX, Config::startY + 60}, 18, 1, DARKGRAY); //Spinnertext
    }
}