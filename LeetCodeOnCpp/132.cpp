class Solution {
public:
	int minCut(string s) {
		int len = s.size();
		if (len <= 1) 
			return 0;

		vector<int> minCUTS(len + 1);
		for (int i = 0; i <= len; ++i)
			minCUTS[i] = i - 1;

		for (int i = 1; i < len; i++) {
			for (int j = 0; (i - j) >= 0 && (i + j) < len && s[i - j] == s[i + j]; ++j)
				minCUTS[i + j + 1] = min(minCUTS[i + j + 1], 1 + minCUTS[i - j]);

			for (int j = 0; (i - j - 1) >= 0 && (i + j) < len && s[i - j - 1] == s[i + j]; ++j)
				minCUTS[i + j + 1] = min(minCUTS[i + j + 1], 1 + minCUTS[i - j - 1]);
		}
		return minCUTS[len];
	}
};