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

	int findSecondMinimumValue(TreeNode* root) {
		preorder(root);
		return dict.size() <= 1 ? -1 : *(++dict.begin());
	}
private:
	set<int> dict;
	void preorder(TreeNode* root) {
		if (!root) return;
		dict.insert(root->val);
		preorder(root->left);
		preorder(root->right);
	}
};