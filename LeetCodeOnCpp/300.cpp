class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		vector<int> dp(len, 1);
		int res = 1;
		for (int i = 1; i < len; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			res = max(res, dp[i]);
		}
		return res;
	}
	
	//http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
	int lengthOfLIS(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
			if (it == res.end()) 
				res.push_back(nums[i]);
			else 
				*it = nums[i];
		}
		return res.size();
	}
};