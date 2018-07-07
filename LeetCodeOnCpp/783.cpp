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
	int res = INT_MAX, pre = -1;
public:
	int mindiffInBST(TreeNode* root) {
		if (root->left != nullptr)
			mindiffInBST(root->left);
		if (pre >= 0)
			res = min(res, root->val - pre);
		pre = root->val;
		if (root->right != nullptr)
			mindiffInBST(root->right);
		return res;
	}
};