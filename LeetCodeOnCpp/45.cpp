class Solution {
public:
	int jump(vector<int>& nums) {
		int i = 0, j = 1, cnt = 0, mx, len = nums.size();
		if (len == 1)
			return 0;

		while (i < len - 1 && i + nums[i] < len - 1) {
			for (mx = j; j <= i + nums[i]; j++) {
				mx = (mx + nums[mx] <= j + nums[j]) ? j : mx;
			}
			i = mx;
			cnt++;
		}
		return ++cnt;
	}
};