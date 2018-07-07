class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		dfs(nums, 0, res);
		return res;
	}

	void dfs(vector<int> &num, int pos, vector<vector<int>> &res) {
		if (pos == num.size()) {
			res.push_back(num);
		}
		else {
			for (int i = pos; i < num.size(); i++) {
				swap(num[i], num[pos]);
				dfs(num, pos + 1, res);
				swap(num[i], num[pos]);
			}
		}
	}
};