class Solution {
public:
	int findRotateSteps(string ring, string key) {
		int rsize = ring.size();
		int ksize = key.size();
		unordered_map<char, vector<int>> mp;
		for (int i = 0; i < rsize; i++)
			mp[ring[i]].push_back(i);

		vector<vector<int>> dp(ksize + 1, vector<int>(rsize, INT_MAX));
		fill(dp[0].begin(), dp[0].end(), 0);
		vector<int> tmp(1, 0);
		int res = INT_MAX;
		for (int i = 1; i <= ksize; ++i) {
			for (auto it : mp[key[i - 1]]) {
				for (int j = 0; j < tmp.size(); ++j) {
					int minDist = min((tmp[j] + rsize - it) % rsize, (it + rsize - tmp[j]) % rsize) + dp[i - 1][tmp[j]];
					dp[i][it] = min(dp[i][it], minDist);
					res = (i != ksize ? res : min(res, dp[i][it]));
				}
			}
			tmp = mp[key[i - 1]];
		}
		return res + ksize;
	}
};