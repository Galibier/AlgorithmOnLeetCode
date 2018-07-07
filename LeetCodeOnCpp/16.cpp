class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		int n = nums.size();
		int distance = INT_MAX;
		int result;

		for (int i = 0; i < n - 2; i++) {
			if (i > 0 && nums[i - 1] == nums[i])
				continue;
			int a = nums[i];
			int low = i + 1;
			int high = n - 1;

			while (low < high) {
				int b = nums[low];
				int c = nums[high];
				int sum = a + b + c;
				if (sum - target == 0) {
					return target;
				}
				else {
					if (abs(sum - target) < distance) {
						distance = abs(sum - target);
						result = sum;
					}
					if (sum - target > 0) {
						while (high > 0 && nums[high] == nums[high - 1])
							high--;
						high--;
					}
					else {
						while (low < n&&nums[low] == nums[low + 1])
							low++;
						low++;
					}
				}
			}
		}
		return result;
	}
};