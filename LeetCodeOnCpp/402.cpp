class Solution {
public:
	string removeKdigits(string num, int k) {
		int digitsCnt = num.size() - k;
		vector<char> stack;

		if (num.empty())
			return "0";
		stack.push_back(num[0]);
		for (unsigned i = 1; i < num.size(); i++) {
			char c = stack.back();
			while (num[i] < c&&k>0) {
				stack.pop_back();
				k--;
				if (stack.empty())
					break;
				else
					c = stack.back();
			}
			stack.push_back(num[i]);
		}
		vector<char> digits(stack.begin(), stack.begin() + digitsCnt);
		unsigned j = 0;
		while (!digits.empty() && digits[j] == '0')
			++j;

		string result(digits.begin() + j, digits.end());
		if (result.empty())
			return string("0");
		return result;
	}
};