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
	int sumNumbers(TreeNode *root) {
		if (root == nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr)
			return root->val;
		
		return (root->left ? root->left->val += root->val * 10, sumNumbers(root->left) : 0)
			+ (root->right ? root->right->val += root->val * 10, sumNumbers(root->right) : 0);
	}
};