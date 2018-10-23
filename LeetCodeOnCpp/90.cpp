#include "head_file.h"

class Solution {
private:
    void subsetsWithDup(vector<int> &nums, vector<int> res, vector<vector<int>> &ans, int start) {
        ans.push_back(res);
        for (int i = start; i != nums.size(); ++i) {
            if (i == start || nums[i] != nums[i - 1]) {
                res.push_back(nums[i]);
                subsetsWithDup(nums, res, ans, i + 1);
                res.pop_back();
            }
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<int> res;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, res, ans, 0);
        return ans;
    }
};