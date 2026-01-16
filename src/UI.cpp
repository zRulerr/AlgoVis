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
    }
}