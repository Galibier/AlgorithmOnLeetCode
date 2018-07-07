class Solution {
public:
	bool isSubsequence(string s, string t) {
		int sLen = s.size(), sIdx = 0, tLen = t.size();
		for (int i = 0; i < tLen && sIdx < sLen; i++)
			if (t[i] == s[sIdx]) sIdx++;
		return sIdx == sLen;
	}
};