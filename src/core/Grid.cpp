#include "Grid.hpp"
// if(x >= 0 && x < gridWidth && y >= 0 && y < gridHeight)

Grid::Grid(): GridWidth(30), GridHeight(10) {
}

int get_GridWidth() const{
    return GridWidth;
}

int get_GridHeight() const{
    return GridHeight;
}