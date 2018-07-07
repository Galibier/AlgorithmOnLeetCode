class Solution {
public:
	void recursion(vector<int> num, int l, int r, vector<vector<int> > &res) {
		if (l == r - 1) {
			res.push_back(num);
			return;
		}
		for (int k = l; k < r; k++) {
			if (l != k && num[l] == num[k]) continue;
			swap(num[l], num[k]);
			recursion(num, l + 1, r, res);
		}
	}
	vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int> >res;
		recursion(num, 0, num.size(), res);
		return res;
	}
};