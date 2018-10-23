#include "head_file.h"

class Solution {
public:
    int mySqrt(int x) {
        unsigned left = 1, right = (1 << 16) - 1;
        while (left <= right) {
            unsigned mid = (left + right) / 2;
            if (x == pow(mid, 2)) {
                right = mid;
                break;
            } else if (x < pow(mid, 2)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};