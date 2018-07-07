class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		char ret = letters[0];
		for (auto iter = letters.begin(); iter != letters.end(); iter++)
			if (*iter > target) {
				ret = *iter;
				break;
			}
		return ret;
	}
};