class Solution {
public:
	int findLUSlength(vector<string>& strs) {
		unordered_map<string, int> freq;
		map<int, int> res;
		int max_length = strs[0].size();
		freq[strs[0]]++;
		res[strs[0].size()]++;
		int result = -1;
		for (int i = 1; i < strs.size(); i++) {
			if (strs[i].size() > max_length) {
				max_length = strs[i].size();
				freq[strs[i]]++;
				res[max_length]++;
			}
			else {
				if (freq.find(strs[i]) != freq.end()) {
					if (freq[strs[i]] > 0) {
						res[strs[i].length()]--;
						freq[strs[i]]--;
					}
				}
				else {
					if (!canBeSubsequence(strs[i], strs, i)) {
						freq[strs[i]]++;
						res[strs[i].size()]++;
					}
				}
			}
		}
		for (auto i : res) {
			if (i.second > 0)
				result = max(result, i.first);
		}
		return result;
	}

private:
	bool canBeSubsequence(string s, vector<string>& strs, int index) {
		for (int i = 0; i < index; i++) {
			string str = strs[i];
			int k = 0;
			for (int j = 0; j < str.length(); j++) {
				if (str[j] == s[k])
					k++;
			}
			if (k == s.length())
				return true;
		}
		return false;
	}
};