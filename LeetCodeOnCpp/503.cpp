class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> next(n, -1);
		stack<int> stk;
		for (int i = 0; i < n * 2; ++i) {
			int num = nums[i%n];
			while (!stk.empty() && nums[stk.top()] < num) {
				next[stk.top()] = num;
				stk.pop();
			}
			if (i < n)
				stk.push(i);
		}
		return next;
	}
};