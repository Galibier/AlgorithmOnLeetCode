class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> ret;
		for (int i = 0; i < nums.size(); i++)
			while (nums[i] != nums[nums[i] - 1])
				swap(nums[i], nums[nums[i] - 1]);
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != i + 1) {
				ret.push_back(nums[i]);
				ret.push_back(i + 1);
			}
		return ret;
	}
};