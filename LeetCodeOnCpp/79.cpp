class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
				if (bfs(board, i, j, word, 0))
					return true;
		return false;
	}
private:
	bool bfs(vector<vector<char>>& board, int i, int j, string word, int idx) {
		if (idx == word.size())
			return true;
		if (i < 0 || j < 0 || i == board.size() || j == board[0].size())
			return false;
		if (board[i][j] != word[idx])
			return false;
		char t = board[i][j];
		board[i][j] = '\0';
		bool ret = bfs(board, i, j + 1, word, idx + 1) ||
			bfs(board, i, j - 1, word, idx + 1) ||
			bfs(board, i + 1, j, word, idx + 1) ||
			bfs(board, i - 1, j, word, idx + 1);
		board[i][j] = t;
		return ret;
	}
};