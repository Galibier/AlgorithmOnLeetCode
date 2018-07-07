class Solution {
public:
	bool judgeSquareSum(int c) {
		int n = (int)sqrt(c + 1);
		vector<int> tmp(n + 1);
		for (int i = 0; i <= n; i++) {
			tmp[i] = i * i;
		}
		int l = 0, r = n;
		while (r >= l) {
			if (tmp[l] + tmp[r] == c)
				return true;
			else if (tmp[l] + tmp[r] < c)
				l++;
			else
				r--;
		}
		return false;
	}
};