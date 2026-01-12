#include <catch2/catch_test_macros.hpp>
#include "core/Grid.hpp"

TEST_CASE("Grid Index Check", "[Grid]") {
    // 10 x 10 test grid
    Grid testGrid(10, 10); 

    SECTION("Valid indices should return true") {
        // Test the middle and the edges
        CHECK(testGrid.isNotOutOfGrid(0) == true);   // Top left
        CHECK(testGrid.isNotOutOfGrid(99) == true);  // Down right
        CHECK(testGrid.isNotOutOfGrid(50) == true);  // middle
    }

    SECTION("Invalid indices should return false") {
        CHECK(testGrid.isNotOutOfGrid(-1) == false);  // too small
        CHECK(testGrid.isNotOutOfGrid(100) == false); // too big by 1
        CHECK(testGrid.isNotOutOfGrid(500) == false); // way too big
    }
}