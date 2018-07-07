class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> fromBegin(len);
		fromBegin[0] = 1;
		vector<int> fromLast(len);
		fromLast[0] = 1;

		for (int i = 1; i < len; i++) {
			fromBegin[i] = fromBegin[i - 1] * nums[i - 1];
			fromLast[i] = fromLast[i - 1] * nums[len - i];
		}

		vector<int> res(len);
		for (int i = 0; i < len; i++) {
			res[i] = fromBegin[i] * fromLast[len - 1 - i];
		}
		return res;
	}
};