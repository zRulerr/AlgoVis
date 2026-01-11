#pragma once

#include "Node.hpp"
#include <vector>


class Grid
{
private:
    std::vector<Node> nodes;

    int GridWidth;
    int GridHeight;
public:
    Grid();
    ~Grid() = default;

    int getGridWidth() const;
    int getGridHeight() const;

    
};