class Solution {
	void solve(vector<vector<string>>& result, vector<int>& r, int curRow) {
		for (int xPos = 0; xPos < r.size(); xPos++) {
			r[curRow] = xPos;
			bool isSafe = true;
			for (int i = 0; i < curRow; i++) {
				if (r[i] == xPos || abs(curRow - i) == abs(xPos - r[i])) {
					isSafe = false;
					break;
				}
			}
			if (isSafe&&curRow == r.size() - 1) {
				vector<string> v(r.size(), string(r.size(), '.'));
				for (int i = 0; i < r.size(); i++)
					v[i][r[i]] = 'Q';
				result.push_back(v);
			}
			else if (isSafe) {
				solve(result, r, curRow + 1);
			}
		}
	}

public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result; 
		vector<int> r(n, -1);
		solve(result, r, 0);
		return result;
	}
};