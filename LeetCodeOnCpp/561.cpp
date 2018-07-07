class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int ret = 0;
		bool flag = true;
		array<int, 20001> hashtable{ 0 };
		for (const auto n : nums) {
			++hashtable[n + 10000];
		}
		for (int i = 0; i < 20001;) {
			if (hashtable[i] > 0) {
				if (flag) {
					flag = false;
					ret += (i - 10000);
					--hashtable[i];
				}
				else {
					flag = true;
					--hashtable[i];
				}
			}
			else
				++i;
		}
		return ret;
	}
};