#include <catch2/catch_test_macros.hpp>
#include "core/Grid.hpp"

TEST_CASE("Grid Neighbor Check", "[Grid]") {
    // 6 x 4 test grid
    Grid testGrid(6, 4); 

    SECTION("Valid indices should return true") {
        CHECK(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(7, Direction::UP))); 
        CHECK(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(7, Direction::DOWN))); 
        CHECK(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(7, Direction::LEFT))); 
        CHECK(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(7, Direction::RIGHT))); 
    }

    SECTION("Invalid indices should return false") {
        CHECK_FALSE(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(0, Direction::UP))); 
        CHECK_FALSE(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(23, Direction::DOWN))); 
        CHECK_FALSE(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(0, Direction::LEFT))); 
        CHECK_FALSE(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(23, Direction::RIGHT))); 
    }
}
