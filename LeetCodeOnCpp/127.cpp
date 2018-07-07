class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		if (dict.count(endWord) == 0)
			return 0;
		dict.erase(endWord);

		unordered_set<string> set1({ beginWord });
		unordered_set<string> set2({ endWord });
		unordered_set<string> tmp;
		int step = 0;

		while (!set1.empty()) {
			step++;
			tmp.clear();
			for (auto s : set1) {
				for (auto &c : s) {
					const char origin = c;
					for (int i = 0; i < 26; i++) {
						c = 'a' + i;
						if (set2.count(s) > 0) {
							return step + 1;
						}
						else if (dict.count(s) > 0) {
							dict.erase(s);
							tmp.insert(s);
						}
					}
					c = origin;
				}
			}
			set1 = (tmp.size() < set2.size() ? tmp : set2);
			set2 = (tmp.size() < set2.size() ? set2 : tmp);
		}
		return 0;
	}
};