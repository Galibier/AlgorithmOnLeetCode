class Solution {
public:
	vector<vector<int>> subsets(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int cnt = pow(2, len);
		vector<vector<int>> set(cnt, vector<int>());
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < cnt; j++) {
				if ((j >> i) & 1)
					set[j].push_back(nums[i]);
			}
		}
		return set;
	}
};