#pragma once

#include "Node.hpp"
#include <vector>

/**
 * @class Grid
 * @brief Manages a 2D-Grid and individual Cells
 * 
 * This class saves Nodes in a std::vector and uses Methods
 * to gain access and manange them
 */

class Grid
{
private:
    std::vector<Node> nodes;

    int GridWidth;
    int GridHeight;
    int Index;

public:
    Grid();
    ~Grid() = default;

    /**
     * @brief Return the Width of the Grid
     */
    int getGridWidth() const;
    /**
     * @brief Return the Height of the Grid
     */
    int getGridHeight() const;
    /**
     * @brief Return the Index of the current Cell/Node
     */
    int getIndex() const;

    /**
     * @brief A Method to convert the x and y coordinates of a Node to the Index
     */
    int coordsToIndex(int x, int y) const;
    /**
     * @brief A Method to convert the Index into the x and y coordinates of a Node
     */
    int indexToCoords(int i) const;
    
};