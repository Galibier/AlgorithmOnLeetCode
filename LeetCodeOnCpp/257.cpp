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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ret;
		if (root == nullptr)
			return ret;

		search(ret, root, to_string(root->val));
		return ret;
	}

	void search(vector<string> &ret, TreeNode* root, string tmp) {
		if (root->left == nullptr&&root->right == nullptr) {
			ret.push_back(tmp);
			return;
		}
		if (root->left)search(ret, root->left, tmp + "->" + to_string(root->left->val));
		if (root->right)search(ret, root->right, tmp + "->" + to_string(root->right->val));
	}
};