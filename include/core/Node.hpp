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
        bool wall;
        float weight;

    public:
        Node();
        ~Node() = default;

        /**
         * @brief A Method to get the current Wall state
         */
        auto getWall() const -> bool;

        /**
         * @brief A Method to toggle the current Wall state between true and false
         */
        auto toggleWall() -> void;

        /** @brief A Method to set Wall as the current status */
        auto setWall(bool status) -> bool;
};