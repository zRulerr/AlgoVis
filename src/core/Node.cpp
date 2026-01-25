#include "Node.hpp"

Node::Node(): visited(false), wall(false), weight(1.0) {
}

auto Node::getWall() const -> bool {
    return wall;
}

auto Node::setWall(bool status) -> bool {
    return wall = status;
}

auto Node::toggleWall() -> void {
    wall = !wall;
}