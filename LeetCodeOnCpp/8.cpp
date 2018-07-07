class Solution {
public:
	int myAtoi(string str) {
		if (str.length() == 0)
			return 0;

		long long ret = 0;
		int index = 0;
		for (; index < str.size() && isspace(str[index]); index++)
			;

		bool isNegative = false;
		if (str[index] == '-' || str[index] == '+')
			isNegative = (str[index++] == '-');

		for (; isdigit(str[index]); index++) {
			int digit = (str[index] - '0');
			if (isNegative) {
				if (-ret < (INT_MIN + digit) / 10) {
					return INT_MIN;
				}
			}
			else {
				if (ret > (INT_MAX - digit) / 10) {
					return INT_MAX;
				}
			}
			ret = ret * 10 + digit;
		}
		return isNegative ? -ret : ret;
	}
};