class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0)
			return 0;

		vector<int> dp(s.size() + 1);
		dp[0] = 1;
		for (int i = 1; i < s.size(); i++) {
			int j = 1;
			for (; j < dp[i - 1]; j++) {
				if (s[i] == s[i - j])
					break;
			}
			if (s[i] == s[i - j])
				dp[i] = j;
			else
				dp[i] = dp[i - 1] + 1;
		}

		return *max_element(dp.begin(), dp.end());
	}
};