class Solution {
public:
	int evalRPN(vector<string> &n) {
		string s = n.back();
		n.pop_back();
		if (s == "*" || s == "/" || s == "+" || s == "-") {
			int r2 = evalRPN(n);
			int r1 = evalRPN(n);
			if (s == "*") return r1 * r2;
			if (s == "/") return r1 / r2;
			if (s == "+") return r1 + r2;
			if (s == "-") return r1 - r2;
		}
		else
			return atoi(s.c_str());
	}
};