class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() <= 0)
			return string();
		int i, minLength = strs[0].length();
		for (i = 1; i < strs.size(); i++)
			if (strs[i].length() < minLength)
				minLength = strs[i].length();

		bool unMatch = false;
		for (i = 0; i < minLength; i++) {
			for (int j = 1; j < strs.size(); j++)
				if (strs[0][i] != strs[j][i]) {
					unMatch = true;
					break;
				}
			if (unMatch)
				break;
		}
		return strs[0].substr(0, i);
	}
};