#include "Grid.hpp"
// if(x >= 0 && x < gridWidth && y >= 0 && y < gridHeight)

Grid::Grid(): GridWidth(30), GridHeight(10) {
}

int Grid::getGridWidth() const{
    return GridWidth;
}

int Grid::getGridHeight() const{
    return GridHeight;
}

int Grid::getIndex() const{
    return Index;
}

int Grid::coordsToIndex(int x, int y) const{
    return y * GridWidth + x;
}

int Grid::indexToCoords(int i) const {

}