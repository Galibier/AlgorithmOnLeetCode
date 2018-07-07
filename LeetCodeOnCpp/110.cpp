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
	bool isBalanced(TreeNode* root) {
		return postOrder(root) == -1 ? false : true;
	}

	int postOrder(TreeNode *root) {
		if (root == nullptr)
			return 0;
		int l = postOrder(root->left);
		int r = postOrder(root->right);
		if (l == -1 || r == -1 || abs(l - r) > 1)
			return -1;
		return max(l, r) + 1;
	}
};