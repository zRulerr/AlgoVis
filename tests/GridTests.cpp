#include <catch2/catch_test_macros.hpp>
#include "core/Grid.hpp"

TEST_CASE("Grid Index Check", "[Grid]") {
    // 10 x 10 test grid
    Grid testGrid(10, 10); 

    SECTION("Valid indices should return true") {
        // Test the middle and the edges
        CHECK(testGrid.isNotOutOfGrid(0));   // Top left
        CHECK(testGrid.isNotOutOfGrid(99));  // Down right
        CHECK(testGrid.isNotOutOfGrid(50));  // middle
    }

    SECTION("Invalid indices should return false") {
        CHECK_FALSE(testGrid.isNotOutOfGrid(-1));  // too small
        CHECK_FALSE(testGrid.isNotOutOfGrid(100)); // too big by 1
        CHECK_FALSE(testGrid.isNotOutOfGrid(500)); // way too big
    }
}