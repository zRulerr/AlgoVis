#pragma once

#include "Node.hpp"
#include "Types.hpp"
#include <vector>
#include <utility> 

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
    Grid(int width, int height);
    ~Grid() = default;

    /**
     * @brief Return the Width of the Grid
     */
    auto getGridWidth() const -> int;
    /**
     * @brief Return the Height of the Grid
     */
    auto getGridHeight() const -> int;
    /**
     * @brief Return the Index of the current Cell/Node
     */
    auto getIndex() const -> int;

    /**
     * @brief A Method to convert the x and y coordinates of a Node to the Index
     */
    auto coordsToIndex(int column, int row) const -> int;
    /**
     * @brief A Method to convert the Index into the x and y coordinates of a Node, returns a std::pair
     *  The library <utility> is needed for this
     */
    auto indexToCoords(int index) const -> std::pair<int, int>;

    /**
     * @brief A Method to check if the index has not stepped outside the Grid
     */
    auto isNotOutOfGrid(int index) const -> bool;

    /**
     * @brief A Method to check if the current Node /Index is walkable (!wall) or not walkable (wall)
     */
    auto isWalkable(int index) const -> bool;

    /**
     * @brief A Method to toggle the current index /Node to a Wall or not
     */
    auto toggleWallAt(int index) -> void;

    /**
     * @brief A Method to calculate the neighbours of the current index
     */
    auto getNeighborIndex(int index, Direction dir) -> int;
    
};