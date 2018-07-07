class Solution {
public:
	int superPow(int a, vector<int>& b) {
		if (b.empty())
			return 1;

		int last_digit = b.back();
		b.pop_back();
		return powMod(superPow(a, b), 10)*powMod(a, last_digit) % base;
	}
private:
	const int base = 1337;
	int powMod(int a, int k) {
		a %= base;
		int ret = 1;
		for (int i = 0; i < k; ++i) {
			ret = (ret*a) % base;
		}
		return ret;
	}
};