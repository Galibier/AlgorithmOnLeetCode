class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int>path;
		backtrack(result, path, 1, k, n);
		return result;
	}

	void backtrack(vector<vector<int>> &res, vector<int> &path, int start, int k, int target) {
		if (target == 0 && k == 0)
			res.push_back(path);
		else {
			for (int i = start; i <= 10 - k && i <= target; i++) {
				path.push_back(i);
				backtrack(res, path, i + 1, k - 1, target - i);
				path.pop_back();
			}
		}
	}
};