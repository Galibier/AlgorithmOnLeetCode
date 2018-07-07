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
	TreeNode * deleteNode(TreeNode* root, int key) {
		if (root == nullptr)
			return nullptr;
		if (root->val == key) {
			if (root->right == nullptr) {
				TreeNode* left = root->left;
				delete root;
				return left;
			}
			else {
				TreeNode* right = root->right;
				while (right->left)
					right = right->left;
				swap(root->val, right->val);
			}
		}
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		return root;
	}
};