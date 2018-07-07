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
	void flatten(TreeNode *root) {
		while (root != nullptr) {
			if (root->left != nullptr && root->right != nullptr) {
				TreeNode* t = root->left;
				while (t->right)
					t = t->right;
				t->right = root->right;
			}

			if (root->left != nullptr)
				root->right = root->left;
			root->left = nullptr;
			root = root->right;
		}
	}
};