#include "UI.hpp"
#include "raygui.h"

namespace UI {
        auto SetupStyle() -> Font {
        //Custom Font init
        Font customFont = LoadFontEx("resources/Inter_24pt-Regular.ttf", 96, 0, 250);
        SetTextureFilter(customFont.texture, TEXTURE_FILTER_BILINEAR);

        GuiSetFont(customFont);
        GuiSetStyle(DEFAULT, TEXT_SIZE, 24);

        return customFont;
    }
}