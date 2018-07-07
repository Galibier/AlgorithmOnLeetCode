class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = 0, val;
		for (int i = 0; i < nums.size(); i++) {
			if (count == 0) {
				val = nums[i];
				count++;
				continue;
			}
			if (nums[i] == val)
				count++;
			else {
				count--;
			}
		}
		return val;
	}
};