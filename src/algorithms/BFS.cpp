#include "BFS.hpp"

BFS::BFS(Grid& grid) : m_grid(grid) {}

auto BFS::initPath(int startIndex, int endIndex) -> void{
    //reset
    m_frontier = std::queue<int>(); //empty queue
    m_cameFrom.clear();
    m_visitedOrder.clear();
    m_found = false;
    
    //
    if (!m_grid.isWalkable(startIndex) || !m_grid.isWalkable(endIndex)) return;

    //
    m_frontier.push(startIndex);
    m_cameFrom[startIndex] = startIndex;
    m_visitedOrder.push_back(startIndex);
}

auto BFS::step(int targetIndex) -> void {
    if (m_frontier.empty() || m_found) return;

    int current = m_frontier.front();
    m_frontier.pop();

    // Diese Prüfung hier ist okay, aber meist redundant, 
    // wenn wir sie unten beim Entdecken machen.
    if (current == targetIndex) {
        m_found = true;
        return;
    }

    for (int d = 0; d < 4; ++d) {
        int next = m_grid.getNeighborIndex(current, static_cast<Direction>(d));
        
        if (next != -1 && m_grid.isWalkable(next) && m_cameFrom.find(next) == m_cameFrom.end()) {
            m_frontier.push(next);
            m_cameFrom[next] = current;
            m_visitedOrder.push_back(next);

            // SOFORT PRÜFEN: Ist dieser neue Nachbar unser Ziel?
            if (next == targetIndex) {
                m_found = true;
                return; // Algorithmus sofort stoppen
            }
        }
    }
}

auto BFS::reconstructPath(const std::unordered_map<int, int>& cameFrom, int start, int target) -> std::vector<int> {
    std::vector<int> path;
    int current = target;
    
    while (current != start) {
        path.push_back(current);
        current = cameFrom.at(current);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}