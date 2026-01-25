#pragma once

struct AppState {
    int scrollIndex = 0;
    int activeAlg = 0;
    bool listViewEditMode = false;
    float algorythmSpeed = 10.0f;

    bool isRunning = true;
    bool toggleBuildWall = false;
};
