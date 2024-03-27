#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> readMatrixFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open " << filename << endl;
        exit(1);
    }

    int n;
    file >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close();
    return matrix;
}

void updateMatrices(vector<vector<int>>& D_minus1, vector<vector<int>>& D_0, vector<vector<int>>& D_plus1) {
    int n = D_0.size(); 

    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if ((D_minus1[i][k] + D_plus1[k][j] == 0) || (D_plus1[i][k] + D_minus1[k][j] == 0)) {
                        D_0[i][j] = 0;
                    }
                    if ((D_plus1[i][k] + D_0[k][j] == 1) || (D_0[i][k] + D_plus1[k][j] == 1)) {
                        D_plus1[i][j] = +1;
                    }
                    if ((D_minus1[i][k] + D_0[k][j] == -1) || (D_0[i][k] + D_minus1[k][j] == -1)) {
                        D_minus1[i][j] = -1;
                    }
                }
            }
        }
    }
}
/*
int main() {
    auto D_minus1 = readMatrixFromFile("Dminus1.txt");
    auto D_0 = readMatrixFromFile("D0.txt");
    auto D_plus1 = readMatrixFromFile("Dplus1.txt");

    updateMatrices(D_minus1, D_0, D_plus1);

    
    
    cout << "Updated D(0) Matrix:" << endl;
    for (const auto& row : D_0) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
*/