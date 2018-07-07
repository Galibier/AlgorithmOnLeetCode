class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		int remove_left = 0, remove_right = 0, pair = 0;
		unordered_set<string> result;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				remove_left++;
			else if (s[i] == ')') {
				if (remove_left > 0)
					remove_left--;
				else
					remove_right++;
			}
		}
		help(0, 0, remove_left, remove_right, s, "", result);
		return vector<string>(result.begin(), result.end());
	}
private:
	void help(int pair, int index, int remove_left, int remove_right, const string& s, string solution, unordered_set<string>& result) {
		if (index == s.size()) {
			if (pair == 0 && remove_left == 0 && remove_right == 0)
				result.insert(solution);
			return;
		}
		if (s[index] == '(') {
			if (remove_left > 0)
				help(pair, index + 1, remove_left - 1, remove_right, s, solution, result);
			help(pair + 1, index + 1, remove_left, remove_right, s, solution + s[index], result);
		}
		else if (s[index] == ')') {
			if (remove_right > 0)
				help(pair, index + 1, remove_left, remove_right - 1, s, solution, result);
			if (pair > 0)
				help(pair - 1, index + 1, remove_left, remove_right, s, solution + s[index], result);
		}
		else
			help(pair, index + 1, remove_left, remove_right, s, solution + s[index], result);
	}
};