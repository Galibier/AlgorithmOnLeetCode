class Solution {
public:
	bool judgeCircle(string moves) {
		int R = 0, L = 0, U = 0, D = 0;
		for (char c : moves) {
			if (c == 'R')R++;
			else if (c == 'L')L++;
			else if (c == 'U')U++;
			else if (c == 'D')D++;
		}
		return R == L && U == D;
	}
};