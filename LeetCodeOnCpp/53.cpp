class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto max_sum = INT_MIN, sum = 0;
        for (auto n : nums)	{
            sum = max(n, sum + n);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};