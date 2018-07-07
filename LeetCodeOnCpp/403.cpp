class Solution {
	unordered_map<int, bool> dp;
public:
	bool canCross(vector<int>& stone, int pos = 0, int k = 0) {
		int key = pos | k << 11;
		if (dp.count(key) > 0)
			return dp[key];

		for (int i = pos + 1; i < stone.size(); i++) {
			int gap = stone[i] - stone[pos];
			if (gap < k - 1)
				continue;
			if (gap > k + 1)
				return dp[key] = false;
			if (canCross(stone, i, gap))
				return dp[key] = true;
		}
		return dp[key] = (pos == stone.size() - 1);
	}
};