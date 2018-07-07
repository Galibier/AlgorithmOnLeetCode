/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		vector<int> lefts;
		int maxwidth = 0;
		dfs(root, 1, 0, lefts, maxwidth);
		return maxwidth;
	}
private:
	void dfs(TreeNode* node, int id, int depth, vector<int>& lefts, int& maxwidth) {
		if (node == nullptr) 
			return;
		if (depth >= lefts.size()) 
			lefts.push_back(id);
		maxwidth = max(maxwidth, id + 1 - lefts[depth]);

		dfs(node->left, id * 2, depth + 1, lefts, maxwidth);
		dfs(node->right, id * 2 + 1, depth + 1, lefts, maxwidth);
	}
};