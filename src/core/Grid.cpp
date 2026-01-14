#include "Grid.hpp"

Grid::Grid(int width, int height) 
    : GridWidth(width), GridHeight(height) {
    //Vector size 
    nodes.resize(width * height);
}

auto Grid::getGridWidth() const -> int{
    return GridWidth;
}

auto Grid::getGridHeight() const -> int{
    return GridHeight;
}

auto Grid::getIndex() const -> int{
    return Index;
}

auto Grid::coordsToIndex(int column, int row) const -> int{
    return (row * GridWidth) + column;
}

auto Grid::indexToCoords(int index) const -> std::pair<int, int>{
    int column = index % GridWidth;
    int row = index / GridWidth;
    return{column, row};
}

auto Grid::isNotOutOfGrid(int index) const -> bool {
    //Hier test einbauen
    std::pair<int, int> position = indexToCoords(index); 

    int x = position.first;
    int y = position.second;   

    return (x >= 0 && x < GridWidth && y >= 0 && y < GridHeight);
}