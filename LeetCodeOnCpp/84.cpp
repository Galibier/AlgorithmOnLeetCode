class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int len = height.size();
		stack<int> stk;
		int maxAera = 0;
		for (int i = 0; i <= len; i++) {
			int h = (i == len ? 0 : height[i]);
			if (stk.empty() || h >= height[stk.top()]) {
				stk.push(i);
			}
			else {
				int tp = stk.top();
				stk.pop();
				maxAera = max(maxAera, height[tp] * (stk.empty() ? i : i - 1 - stk.top()));
				i--;
			}
		}
		return maxAera;
	}
};