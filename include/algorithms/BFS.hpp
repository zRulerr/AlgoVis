#pragma once

#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include "Grid.hpp"

class BFS {
private:
    Grid& m_grid;
    std::vector<int> m_visitedOrder;

    std::queue<int> m_frontier;
    std::unordered_map<int, int> m_cameFrom;
    bool m_found = false;

public:
    explicit BFS(Grid& grid);

    auto initPath(int startIndex, int endIndex) -> void;
    auto reconstructPath(const std::unordered_map<int, int>& cameFrom, int start, int target) -> std::vector<int>;


    auto step(int targetIndex) -> void; 
    bool isFinished() const { return m_found || m_frontier.empty();}

    auto isFound() const -> bool {return m_found;}
    auto getVisitedOrder() const -> const std::vector<int>& {return m_visitedOrder;}
    auto getCameFrom() const -> const std::unordered_map<int, int>& {return m_cameFrom;}
};