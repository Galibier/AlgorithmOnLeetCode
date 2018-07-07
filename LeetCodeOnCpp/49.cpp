class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, multiset<string>> mp;
		for (string s : strs) {
			string t = strSort(s);
			mp[t].insert(s);
		}
		vector<vector<string>> anagrams;
		for (auto m : mp) {
			vector<string> anagram(m.second.begin(), m.second.end());
			anagrams.push_back(anagram);
		}

		return anagrams;
	}
private:
	string strSort(string &s) {
		int cnt[26] = { 0 }, n = s.size();
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}
		int p = 0;
		string t(n, 'a');
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < cnt[i]; j++)
				t[p++] += i;
		return t;
	}
};