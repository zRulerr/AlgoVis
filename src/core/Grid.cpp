#include "Grid.hpp"

Grid::Grid(int width, int height) 
    : GridWidth(width), GridHeight(height) {
    //Vector resize to width and height, "resize" expects a size_t therefore the cast
    nodes.resize(static_cast<std::size_t>(width) * static_cast<std::size_t>(height));
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

auto Grid::coordsToIndex(int column, int row, int width) -> int{
    return (row * width) + column;
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

auto Grid::isWalkable(int index) const -> bool {
    //Check if still inside the grid
    if (!isNotOutOfGrid(index)) {
        return false;
    }
    
    //Check if node is a Wall
    if(nodes[index].getWall()) {
        return false;
    }

    return true;
}

auto Grid::toggleWallAt(int index) -> void {
        //Check if still inside the grid
    if (!isNotOutOfGrid(index)) {
        return;
    }

    nodes[index].toggleWall();
}

auto Grid::getNeighborIndex(int currentIndex, Direction dir) const -> int {
    int column = currentIndex % GridWidth; //Calculate current column
    int row = currentIndex / GridWidth;    //Calculate current row 

    switch (dir) {
        case Direction::UP:
            return (row > 0) ? currentIndex - GridWidth : -1;

        case Direction::DOWN:
            return (row < GridHeight - 1) ? currentIndex + GridWidth : -1;

        case Direction::LEFT: 
            return (column > 0) ? currentIndex - 1 : -1;

        case Direction::RIGHT:
            return (column < GridWidth - 1) ? currentIndex + 1 : -1;

        default: return -1;
    }
}

auto Grid::ResizeGrid(std::vector<Node>& nodes, int newCols, int newRows) -> void {
    nodes.clear();
    nodes.resize(newCols * newRows);
}