class Solution {
public:
	bool isMatch(string s, string t) {
		int m = s.size(), n = t.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= n; i++)
			if (t[i - 1] == '*')
				dp[0][i] = dp[0][i - 1];

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				if (t[j - 1] != '*')
					dp[i][j] = dp[i - 1][j - 1] && (t[j - 1] == '?' || s[i - 1] == t[j - 1]);
				else
					dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
			}
		return dp[m][n];
	}
};