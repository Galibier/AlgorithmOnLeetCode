class Solution {
public:
	int calculate(string s) {
		stack <int> nums, ops;
		int num = 0;
		int ret = 0;
		int sign = 1;
		for (char c : s) {
			if (isdigit(c)) {
				num = num * 10 + c - '0';
			}
			else {
				ret += sign * num;
				num = 0;
				if (c == '+') 
					sign = 1;
				if (c == '-') 
					sign = -1;
				if (c == '(') {
					nums.push(ret);
					ops.push(sign);
					ret = 0;
					sign = 1;
				}
				if (c == ')' && ops.size()) {
					ret = ops.top() * ret + nums.top();
					ops.pop(); 
					nums.pop();
				}
			}
		}
		ret += sign * num;
		return ret;
	}
};