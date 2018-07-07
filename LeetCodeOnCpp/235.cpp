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
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* ret = root;
		while (true) {
			if (p->val < ret->val&&q->val < ret->val)
				ret = ret->left;
			else if (p->val > ret->val&&q->val > ret->val)
				ret = ret->right;
			else
				return ret;
		}
	}
};