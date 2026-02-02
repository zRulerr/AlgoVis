#pragma once

/** @brief Enum for the different Paint modes used when drawing Walls */
enum class PaintMode { NONE, PAINTING, ERASING };

/** @brief Struct for Special points such as Start- and Endpoint  */
struct SpecialPoint {   
    int index;
    Color color;
};

/** @brief Struct to store changing Variables throughout Programm runtime */
struct AppState {
    PaintMode currentPaintMode = PaintMode::NONE;

    int scrollIndex = 0;
    int activeAlg = 0;
    bool listViewEditMode = false;
    float algorythmSpeed = 10.0f;

    bool isRunning = true;
    bool toggleBuildWall = false;

    int startNodeIndex = 0; 
    int endNodeIndex = 10;    
};
