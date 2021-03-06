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
private:
	int getLeftHeight(TreeNode* root) {
		int height = 0;
		while (root) {
			root = root->left;
			height++;
		}
		return height;
	}
public:
	int countNodes(TreeNode* root) {
		if (!root) return 0;

		int left_height = getLeftHeight(root->left);
		int right_height = getLeftHeight(root->right);

		if (left_height == right_height)
			return pow(2, left_height) + countNodes(root->right);

		return pow(2, right_height) + countNodes(root->left);
	}
};