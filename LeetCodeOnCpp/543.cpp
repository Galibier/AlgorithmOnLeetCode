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
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int maxD = 0;
		postOrder(root, maxD);
		return maxD;
	}

	int postOrder(TreeNode* root, int &d) {
		int l = 0, r = 0;
		if (root->left != nullptr)
			l = postOrder(root->left, d);
		if (root->right != nullptr)
			r = postOrder(root->right, d);
		d = max(l + r, d);
		return max(l, r) + 1;
	}
};