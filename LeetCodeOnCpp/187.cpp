class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<int, int> m;
		vector<string> ret;
		int t = 0, i = 0, ss = s.size();
		while (i < 9)
			t = t << 3 | s[i++] & 7;
		while (i < ss)
			if (m[t = t << 3 & 0x3fffffff | s[i++] & 7]++ == 1)
				ret.push_back(s.substr(i - 10, 10));
		return ret;
	}
};