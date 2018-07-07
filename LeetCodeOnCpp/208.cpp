class TrieNode {
public:
	TrieNode * next[26];
	bool is_word;

	// Initialize your data structure here.
	TrieNode(bool b = false) {
		memset(next, 0, sizeof(next));
		is_word = b;
	}
};

class Trie {
	TrieNode * root;
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.size(); ++i) {
			if (p->next[word[i] - 'a'] == nullptr)
				p->next[word[i] - 'a'] = new TrieNode();
			p = p->next[word[i] - 'a'];
		}
		p->is_word = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode *p = find(word);
		return p != nullptr && p->is_word;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		return find(prefix) != nullptr;
	}
private:
	TrieNode * find(string key) {
		TrieNode *p = root;
		for (int i = 0; i < key.size() && p != nullptr; ++i)
			p = p->next[key[i] - 'a'];
		return p;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/