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
	int findTilt(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int tilt = 0;
		postorder(root, tilt);
		return tilt;
	}
private:
	int postorder(TreeNode* root, int& res) {
		if (root == nullptr)
			return 0;

		int leftsum = postorder(root->left, res);
		int rightsum = postorder(root->right, res);
		res += abs(leftsum - rightsum);

		return leftsum + rightsum + root->val;
	}
};