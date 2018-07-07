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
bool hasPathSum(TreeNode* root, int target) {
	return postOrder(root, 0, target);
}

bool postOrder(TreeNode* root, int sum, int target) {
    if (root == nullptr)
		return false;
	if (root->left== nullptr&&root->right==nullptr)
		return sum+root->val == target;
	bool left = false;
	bool right = false;
	if (root->left)
		left = postOrder(root->left, sum+root->val, target);
	if (root->right)
		right = postOrder(root->right, sum + root->val, target);
	return left | right;
}
};