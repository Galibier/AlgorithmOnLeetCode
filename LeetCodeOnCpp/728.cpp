class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ret;
		for (int i = left; i <= right; i++) {
			if (isSelfDivided(i))
				ret.push_back(i);
		}
		return ret;
	}

	bool isSelfDivided(int num) {
		int tmp = num;
		while (tmp != 0) {
			if (!(tmp % 10) || num % (tmp % 10))
				return false;
			tmp /= 10;
		}
		return true;
	}
};