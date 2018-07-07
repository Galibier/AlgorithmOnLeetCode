class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		vector<vector<int>> ret = M;
		int row = M.size(), col = M[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int sum = 0, count = 0;
				for (int m = -1; m < 2; m++) {
					for (int n = -1; n < 2; n++) {
						int dx = i + m, dy = j + n;
						if (dx >= 0 && dx < row&&dy >= 0 && dy < col) {
							sum += M[dx][dy];
							count++;
						}
					}
				}
				ret[i][j] = sum / count;
			}
		}
		return ret;
	}
};