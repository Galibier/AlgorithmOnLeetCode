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
	int tryRob(TreeNode* root, int& l, int& r) {
		if (root == nullptr)
			return 0;
		int ll = 0, lr = 0, rl = 0, rr = 0;
		l = tryRob(root->left, ll, lr);
		r = tryRob(root->right, rl, rr);

		return max(root->val + ll + lr + rl + rr, l + r);
	}
public:
	int rob(TreeNode* root) {
		int l, r;
		return tryRob(root, l, r);
	}
};