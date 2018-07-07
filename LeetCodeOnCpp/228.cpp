class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int len = nums.size();
		vector<string> res;
		if (0 == len)
			return res;

		for (int i = 0; i < len;) {
			int start = i, end = i;
			while (end + 1 < len && nums[end + 1] == nums[end] + 1)
				end++;

			if (end > start)
				res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
			else
				res.push_back(to_string(nums[start]));

			i = end + 1;
		}
		return res;
	}
};