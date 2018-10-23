#include "head_file.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;

        int r = m - 1;
        int c = 0;
        while (r >= 0 && c < n) {
            if (target == matrix[r][c])
                return true;
            else if (target > matrix[r][c])
                c++;
            else
                r--;
        }
        return false;
    }
};