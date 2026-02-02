#include "UI.hpp"
#include "raygui.h"

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
    }

    auto CalculateCellSize(const Config::GridSettings& grid) -> float {
        //Check division 
        if (grid.gridCols <= 0 || grid.gridRows <= 0) return 0.0F;

        float cellSizeX = Config::gridArea.width / static_cast<float>(grid.gridCols);
        float cellSizeY = Config::gridArea.height / static_cast<float>(grid.gridRows);

        //Return the smaller Cellsize to get quadratic Cells
        return (cellSizeX < cellSizeY) ? cellSizeX : cellSizeY;
    }

    auto drawGridLines(const Config::GridSettings grid, float cellSize, float offsetX, float offsetY) -> void {
        //Draw Vertical lines
        for (int i = 0; i <= grid.gridCols; i++) {
            float xPos = offsetX + (static_cast<float>(i) * cellSize); 
            
            DrawLineV(
                {xPos, offsetY},//starting point
                {xPos, offsetY + (static_cast<float>(grid.gridRows) * cellSize)},//endpoint
                LIGHTGRAY
            );
        }

        //Draw Horizontal lines
        for (int j = 0; j <= grid.gridRows; j++) {
            float yPos = offsetY + (static_cast<float>(j) * cellSize);

            DrawLineV(
                {offsetX, yPos}, //starting point
                {offsetX + (static_cast<float>(grid.gridCols) * cellSize), yPos}, //endpoint
                LIGHTGRAY
            );
        }
    }

    auto drawMainGuiPanels() -> void {
        GuiPanel(Config::controlElements, "Grid Dimensions");
        GuiPanel(Config::settingsElements, "Settings");
        GuiPanel(Config::playbackElements, "Playback Controls");
    }

    auto drawGUIButtons (AppState &state, BFS &bfs) -> void {
        if (GuiButton(Config::recForStartStopButton, "Start | Stop") != 0) {
            state.isRunning = !state.isRunning;
            if (state.isRunning) {
                // Initialisiert die Queue und Maps im BFS
                bfs.initPath(state.startNodeIndex, state.endNodeIndex);
            }
            TraceLog(LOG_INFO, "Button \"Start /Stop\" has been pressed!");
        }

        //Draw Checkbox
        if (GuiCheckBox(Config::recForDrawWallCheckbox, "Draw walls (toggle)", &state.toggleBuildWall) != 0) {
            TraceLog(LOG_INFO, "Status: %s", state.toggleBuildWall ? "TRUE" : "FALSE");
        }
    }

    auto drawSeperationLines() -> void {
        //Seperation lines
        DrawLine(Config::sidePanelWidth, 0, Config::sidePanelWidth, Config::screenHeight, DARKGRAY); // Links
        DrawLine((int)Config::analyticsPanel.x, 0, (int)Config::analyticsPanel.x, Config::screenHeight, DARKGRAY); // Rechts
    }

    auto drawMainLayout(Font customFont, const Config::GridSettings& grid, AppState& state, BFS& bfs, float cellSize, float offsetX, float offsetY) -> void {
        //Grid Drawing
        drawGridLines(grid, cellSize, offsetX, offsetY);
        
        //Draw Main GUI Panels
        drawMainGuiPanels();

        //Draw Elements like buttons or lists etc.
        drawGUIButtons(state, bfs);

        //Sidepanel Header text
        drawAllTexts(customFont);

        //Seperation Lines drawing
        drawSeperationLines();
    }

    auto setWalls(const Config::GridSettings& grid, Grid& gridLogic, AppState& state, GridTransform transform) -> void {
        if (!state.toggleBuildWall) return;

        float actualGridWidth = static_cast<float>(gridLogic.getGridWidth()) * transform.cellSize;
        float actualGridHeight = static_cast<float>(gridLogic.getGridHeight()) * transform.cellSize;

        Rectangle currentGridRect = { 
            transform.offsetX,
            transform.offsetY,
            actualGridWidth, 
            actualGridHeight
        };

        Vector2 mousePos = GetMousePosition();

        //Check if still in grid
        if (CheckCollisionPointRec(mousePos, currentGridRect)) {

            int col = static_cast<int>((mousePos.x - transform.offsetX) / transform.cellSize);
            int row = static_cast<int>((mousePos.y - transform.offsetY) / transform.cellSize);

            if (col < 0 || col >= gridLogic.getGridWidth() || row < 0 || row >= gridLogic.getGridHeight()) {
                return;
            }

            int index = Grid::coordsToIndex(col, row, gridLogic.getGridWidth());

            //Prohibit setting a Wall at a "special point"
            if (index == state.startNodeIndex || index == state.endNodeIndex) {
                return; //Leave the function for current Frame
            }

            //Set Mode on First Click
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                if (gridLogic.hasWall(index)) {
                    state.currentPaintMode = PaintMode::ERASING;
                } else {
                    state.currentPaintMode = PaintMode::PAINTING;
                }
            }

            //If Mouse is still clicked
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                if (state.currentPaintMode == PaintMode::PAINTING) {
                    gridLogic.setWallAt(index, true);
                } else if (state.currentPaintMode == PaintMode::ERASING) {
                    gridLogic.setWallAt(index, false);
                }
            }
        
        }

        //When mouse is released reset Paint mode
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            state.currentPaintMode = PaintMode::NONE;
        }   
    }

    auto drawWalls(const Grid& gridLogic, float cellSize, float offsetX, float offsetY) -> void {
        for (int i = 0; i < gridLogic.getNodeCount(); i++) {
            if (gridLogic.hasWall(i)) {
                std::pair<int, int> coords = gridLogic.indexToCoords(i);

                DrawRectangleV(
                    {offsetX + (static_cast<float>(coords.first) * cellSize), 
                    offsetY + (static_cast<float>(coords.second) * cellSize)},
                    {cellSize, cellSize },
                    BLACK
                );
            }
        }
    }

    auto drawStartStopPoint(const Grid& gridLogic, AppState& state, GridTransform transform) -> void {
        struct SpecialPoint {int index; Color color;};

        std::array<SpecialPoint, 2> points = {{ 
        {state.startNodeIndex, GREEN}, 
        {state.endNodeIndex, RED} 
    }};

        for (const auto& point : points) {
            if (point.index >= 0 && point.index < gridLogic.getNodeCount()) {
                std::pair<int, int> coords = gridLogic.indexToCoords(point.index);
                
                DrawRectangleV(
                    {transform.offsetX + (static_cast<float>(coords.first) * transform.cellSize), 
                    transform.offsetY + (static_cast<float>(coords.second) * transform.cellSize)},
                    {transform.cellSize, transform.cellSize},
                    point.color
                );
            }
        } 
    }

    auto drawBFSState(const BFS& bfs, const Grid& gridLogic, GridTransform transform, int startIndex, int endIndex) -> void {
        //draw visited nodes
        for (int index : bfs.getVisitedOrder()) {
            std::pair<int, int> coords = gridLogic.indexToCoords(index);
            
            DrawRectangleV(
                {transform.offsetX + (static_cast<float>(coords.first) * transform.cellSize), 
                transform.offsetY + (static_cast<float>(coords.second) * transform.cellSize)},
                {transform.cellSize, transform.cellSize},
                Fade(SKYBLUE, 0.5f)
            );
        }

        //draw path if found
        if (bfs.isFound()) {
            // Wir nutzen die Methode aus deiner BFS Klasse
            // Du musst sicherstellen, dass reconstructPath in der BFS.hpp "public" ist!
            std::vector<int> path = const_cast<BFS&>(bfs).reconstructPath(bfs.getCameFrom(), startIndex, endIndex);

            for (int index : path) {
                // Start und Ende nicht übermalen (optional, sieht aber besser aus)
                if (index == startIndex || index == endIndex) continue;

                std::pair<int, int> coords = gridLogic.indexToCoords(index);
                DrawRectangleV(
                    {transform.offsetX + (static_cast<float>(coords.first) * transform.cellSize), 
                    transform.offsetY + (static_cast<float>(coords.second) * transform.cellSize)},
                    {transform.cellSize, transform.cellSize},
                    GOLD // Goldene Farbe für den Pfad
                );
            }
        }
    }
}