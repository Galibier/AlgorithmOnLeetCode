class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> um;
		if (k <= 0)
			return false;
		if (k >= nums.size())
			k = nums.size() - 1;

		for (int i = 0; i < nums.size(); i++) {
			if (i > k)
				um.erase(nums[i - k - 1]);
			if (um.find(nums[i]) != um.end())
				return true;
			um.insert(nums[i]);
		}
		return false;
	}
};