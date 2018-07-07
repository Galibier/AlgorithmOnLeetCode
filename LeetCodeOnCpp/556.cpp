class Solution {
public:
	int nextGreaterElement(int n) {
		string digits = to_string(n);
		nextPermutation(digits);
		long res = stol(digits);
		if (res >= INT_MAX || res <= n)
			return -1;
		return (int)res;
	}

private:
	void nextPermutation(string& nums) {
		if (nums.empty())
			return;
		int i = nums.size() - 1;
		while (i >= 1 && nums[i] <= nums[i - 1])
			i--;
		if (0 == i)
			return;
		int j = nums.size() - 1;
		while (nums[j] <= nums[i - 1])
			j--;
		swap(nums[i - 1], nums[j]);
		reverse(nums.begin() + i, nums.end());
	}
};