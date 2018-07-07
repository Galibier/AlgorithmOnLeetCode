class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n < 1)
			return 0;
		if (n == 1)
			return nums[0];
		vector<int> ret(n);
		ret[0] = nums[0];
		ret[1] = nums[1];
		ret[2] = nums[0] + nums[2];
		for (int i = 3; i < n; i++) {
			ret[i] = nums[i] + max(ret[i - 2], ret[i - 3]);
		}
		return ret[n - 1] > ret[n - 2] ? ret[n - 1] : ret[n - 2];
	}
};