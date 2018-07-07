class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		set<string> word_set(wordDict.begin(), wordDict.end());
		int len = s.size();
		vector<bool> dp(len + 1, false);
		dp[0] = true;
		for (int i = 1; i <= len; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (dp[j] && word_set.find(s.substr(j, i - j)) != word_set.end()) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[len];
	}
};