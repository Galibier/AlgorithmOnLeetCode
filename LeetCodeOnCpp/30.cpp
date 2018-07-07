class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		int n = s.size(), cnt = words.size();
		if (n <= 0 || cnt <= 0)
			return ans;

		unordered_map<string, int> dict;
		for (int i = 0; i < cnt; ++i)
			dict[words[i]]++;

		int wl = words[0].size();
		for (int i = 0; i < wl; ++i) {
			int left = i, count = 0;
			unordered_map<string, int> tdict;
			for (int j = i; j <= n - wl; j += wl) {
				string str = s.substr(j, wl);
				if (dict.count(str)) {
					tdict[str]++;
					if (tdict[str] <= dict[str])
						count++;
					else {
						while (tdict[str] > dict[str]) {
							string str1 = s.substr(left, wl);
							tdict[str1]--;
							if (tdict[str1] < dict[str1])
								count--;
							left += wl;
						}
					}
					if (count == cnt) {
						ans.push_back(left);
						tdict[s.substr(left, wl)]--;
						count--;
						left += wl;
					}
				}
				else {
					tdict.clear();
					count = 0;
					left = j + wl;
				}
			}
		}
		return ans;
	}
};