class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int max = 0, cur = 0;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] & 1)
				max = max > ++cur ? max : cur;
			else
				cur = 0;

		return max;
	}
};