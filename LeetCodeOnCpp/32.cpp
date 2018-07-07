class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size(), ret = 0;
		stack<int> st;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')
				st.push(i);
			else {
				if (!st.empty()) {
					if (s[st.top()] == '(')
						st.pop();
					else
						st.push(i);
				}
				else
					st.push(i);
			}
		}

		if (st.empty())
			ret = n;
		else {
			int a = n, b = 0;
			while (!st.empty()) {
				b = st.top();
				st.pop();
				ret = max(ret, a - b - 1);
				a = b;
			}
			ret = max(ret, a);
		}
		return ret;
	}
};