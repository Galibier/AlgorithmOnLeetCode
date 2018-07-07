class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <2 || s.size() == 0)
			return s;
		int count = numRows * 2 - 2;
		vector<string> ret(numRows);
		for (int i = 0; i < s.size(); i++) {
			ret[min(i%count, count - i % count)] += s.substr(i, 1);
		}
		string ans;
		for (int i = 0; i < ret.size(); i++) {
			ans += ret[i];
		}
		return ans;
	}
};