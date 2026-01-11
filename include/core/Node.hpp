#pragma once

/**
 * @class Node
 * @brief Manges individual Nodes
 * 
 * A Node has the attributes visited, isWall and weight
 * The Node itself does not know where it is in the Grid,
 * this is managed by the Grid class
 */

class Node {
    private:
        bool visited;
        bool isWall;
        float weight;

    public:
        Node();
        ~Node();
};