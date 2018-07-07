class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> count(nums.size(), 0);
		vector<int> parent(nums.size(), 0);

		int cnt = 0, mi = 0;
		for (int i = nums.size() - 1; i >= 0; --i) {
			for (int j = i; j < nums.size(); ++j) {
				if (nums[j] % nums[i] == 0 && count[i] < 1 + count[j]) {
					count[i] = 1 + count[j];
					parent[i] = j;

					if (count[i] > cnt) {
						cnt = count[i];
						mi = i;
					}
				}
			}
		}
		vector<int> ret;
		for (int i = 0; i < cnt; ++i) {
			ret.push_back(nums[mi]);
			mi = parent[mi];
		}
		return ret;
	}
};