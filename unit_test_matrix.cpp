#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "matrix.h"
#include <cstdlib>

TEST_CASE("Matrix Operations") {
    SUBCASE("Read matrix from file") {
        auto matrix = readMatrixFromFile("D0_test.txt"); 
        CHECK_EQ(matrix.size(), 3); 
        CHECK_EQ(matrix[0][0], 0); 
    }
    
    SUBCASE("Update matrices") {
        std::vector<std::vector<int>> D_minus1 = {{-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
        std::vector<std::vector<int>> D_0 = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
        std::vector<std::vector<int>> D_plus1 = {{0, 0, 1}, {0, 0, 0}, {1, 0, 0}};

        updateMatrices(D_minus1, D_0, D_plus1);

        
        CHECK_EQ(D_0[0][2], 0); 
    }
};