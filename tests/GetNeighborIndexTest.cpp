#include <catch2/catch_test_macros.hpp>
#include "core/Grid.hpp"

TEST_CASE("Grid Neighbor Check", "[Grid]") {
    // 6 x 4 test grid
    Grid testGrid(6, 4); 

    //The Index "7" in a 6x4 Grid is in the middle and has no edge case, all should return true.
    SECTION("Valid indices should return true") {
        CHECK(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(7, Direction::UP))); 
        CHECK(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(7, Direction::DOWN))); 
        CHECK(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(7, Direction::LEFT))); 
        CHECK(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(7, Direction::RIGHT))); 
    }

    //The Indices "0","23" are edge cases (Top left and down right) therefore should return false
    SECTION("Invalid indices should return false") {
        CHECK_FALSE(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(0, Direction::UP))); 
        CHECK_FALSE(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(23, Direction::DOWN))); 
        CHECK_FALSE(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(0, Direction::LEFT))); 
        CHECK_FALSE(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(23, Direction::RIGHT))); 

    //The Index "5" is a line break and should also return false
        CHECK_FALSE(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(5, Direction::RIGHT)));
        CHECK_FALSE(testGrid.isNotOutOfGrid(testGrid.getNeighborIndex(6, Direction::LEFT)));
    }
}
