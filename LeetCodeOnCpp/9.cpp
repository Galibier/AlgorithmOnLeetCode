class Solution {
public:
	bool isPalindrome(int x) {
		bool flag = true;
		if (x < 0)
			flag = false;
		
		long long num = abs(x), ret = 0;
		while (num) {
			ret = ret * 10 + num % 10;
			num /= 10;
		}
		if (ret == x)
			return true;
		return false;
	}
};