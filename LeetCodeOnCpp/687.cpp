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
	int longestUnivaluePath(TreeNode* root) {
		int lenUp = 0;
		if (root) search(root, lenUp);
		return lenUp;
	}

	int search(TreeNode* root, int &length) {
		int leftLen = (root->left ? search(root->left, length) : 0);
		int rightLen = (root->right ? search(root->right, length) : 0);
		int resLeft = (root->left&&root->left->val == root->val ? leftLen + 1 : 0);
		int resRight = (root->right&&root->right->val == root->val ? rightLen + 1 : 0);
		length = max(length, resLeft + resRight);
		return max(resLeft, resRight);
	}
};