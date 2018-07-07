class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
		if (root = nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr) return isleft ? root->val : 0;
		return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
	}
};