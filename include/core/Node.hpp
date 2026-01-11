#pragma once

class Node {
    private:
        bool visited;
        bool isWall;
        float weight;

    public:
        Node();
        ~Node();
};