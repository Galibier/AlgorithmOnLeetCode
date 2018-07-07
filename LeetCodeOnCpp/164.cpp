class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (auto i = 0u; i + 1 < nums.size(); ++i) {
            res = std::max(res, nums[i + 1] - nums[i]);
        }
        return res;
    }
};