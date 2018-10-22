#include "head_file.h"

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int lastPos = nums.size() - 1;
        for (int i = lastPos; i >= 0; i--) {
            if (nums[i] + i >= lastPos)
                lastPos = i;
        }
        return lastPos == 0;
    }
};