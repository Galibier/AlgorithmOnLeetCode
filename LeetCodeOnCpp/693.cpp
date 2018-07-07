class Solution {
public:
	bool hasAlternatingBits(int n) {
		vector<bool> ans;
		while (n > 0) {
			ans.push_back((bool)(n % 2));
			n /= 2;
		}
		for (auto iter = ans.begin(); iter != ans.end() - 1; iter++)
			if (*iter == *(iter + 1))
				return false;
		return true;
	}
};