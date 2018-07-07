class TrieNode {
public:
	bool is_end;
	vector<TrieNode*> children;
	TrieNode() {
		is_end = false;
		children = vector<TrieNode*>(26, nullptr);
	}
};

class Trie {
public:
	TrieNode * getRoot() {
		return root;
	}
	Trie(vector<string> &words) {
		root = new TrieNode();
		for (int i = 0; i < words.size(); ++i) {
			addWord(words[i]);
		}
	}
	void addWord(const string& word) {
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); ++i) {
			int index = word[i] - 'a';
			if (cur->children[index] == nullptr) {
				cur->children[index] = new TrieNode();
			}
			cur = cur->children[index];
		}
		cur->is_end = true;
	}
private:
	TrieNode * root;
};


class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie* trie = new Trie(words);
		TrieNode* root = trie->getRoot();
		set<string> result_set;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				findWords(board, i, j, root, "", result_set);
			}
		}
		
		return vector<string>(result_set.begin(), result_set.end());
	}
private:
	void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& res) {
		if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ')
			return;
		if (root->children[board[x][y] - 'a'] != nullptr) {
			word = word + board[x][y];
			root = root->children[board[x][y] - 'a'];
			if (root->is_end)
				res.insert(word);
			char c = board[x][y];
			board[x][y] = ' ';
			findWords(board, x + 1, y, root, word, res);
			findWords(board, x - 1, y, root, word, res);
			findWords(board, x, y + 1, root, word, res);
			findWords(board, x, y - 1, root, word, res);
			board[x][y] = c;
		}
	}
};
