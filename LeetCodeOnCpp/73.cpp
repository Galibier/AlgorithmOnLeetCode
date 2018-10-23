#include "head_file.h"

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }

    void setZeroes1(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) {
            return;
        }
        std::vector<bool> row(m, false);
        std::vector<bool> col(n, false);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (row[i]) {
                    matrix[i][j] = 0;
                }
                if (col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};