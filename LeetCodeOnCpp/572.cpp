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
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == nullptr && t == nullptr) return true;
		if (s == nullptr || t == nullptr) return false;

		getDepth(s, getDepth(t, -1));

		for (auto n : nodes)
			if (identical(n, t))
				return true;

		return false;
	}
private:
	vector<TreeNode*> nodes;

	int getDepth(TreeNode* root, int d) {
		if (root == nullptr)
			return -1;

		int depth = max(getDepth(root->left, d), getDepth(root->right, d)) + 1;

		if (depth == d)
			nodes.push_back(root);

		return depth;
	}

	bool identical(TreeNode* lhs, TreeNode* rhs) {
		if (lhs == nullptr && rhs == nullptr) return true;
		if (lhs == nullptr || rhs == nullptr || lhs->val != rhs->val) return false;

		return identical(lhs->left, rhs->left) && identical(lhs->right, rhs->right);
	}
};