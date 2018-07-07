class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return false;
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)
				return true;
			if (nums[mid] > nums[r]) {
				if (nums[mid] > target&&nums[l] <= target)
					r = mid;
				else
					l = mid + 1;
			}
			else if (nums[mid] < nums[r]) {
				if (nums[mid] < target&&nums[r] >= target)
					l = mid + 1;
				else
					r = mid;
			}
			else {
				r--;
			}
		}
		return nums[l] == target ? true : false;
	}
};