#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

std::vector<std::vector<int>> readMatrixFromFile(const std::string& filename);
void updateMatrices(std::vector<std::vector<int>>& D_minus1, std::vector<std::vector<int>>& D_0, std::vector<std::vector<int>>& D_plus1);

#endif