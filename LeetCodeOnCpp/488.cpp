class Solution {
public:
	int findMinStep(string board, string hand) {
		unordered_map<char, int> mp;
		for (auto c : hand)
			mp[c]++;
		minStep = INT_MAX;
		dfs(board, mp, 0);
		return minStep == INT_MAX ? -1 : minStep;
	}
private:
	int minStep;

	void dfs(string& board, unordered_map<char, int>& mp, int used) {
		if (board.empty()) {
			minStep = min(minStep, used);
			return;
		}
		for (int i = 0; i < board.size(); ) {
			int j = i;
			char c = board[i];
			while (j < board.size() && board[j] == c)
				j++;
			if (j - i < 3) {
				int miss = 3 - (j - i);
				if (mp[c] >= miss) {
					removeBoard(board, i, j);
					mp[c] -= miss;
					dfs(board, mp, used + miss);
					mp[c] += miss;
					restoreBoard(board, i, j - i, c);
				}
			}
			else {
				removeBoard(board, i, j);
				dfs(board, mp, used);
				restoreBoard(board, i, j - i, c);
			}
			i = j;
		}
	}

	void removeBoard(string& board, int start, int end) {
		board.erase(board.begin() + start, board.begin() + end);
	}

	void restoreBoard(string& board, int pos, int n, char c) {
		board.insert(pos, n, c);
	}
};