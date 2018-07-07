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
	int kthSmallest(TreeNode* root, int k) {
		return inOrder(root, k);
	}
private:
	int inOrder(TreeNode* root, int k) {
		stack<TreeNode*> sTree;
		while (!sTree.empty() || root != nullptr) {
			while (root != nullptr) {
				sTree.push(root);
				root = root->left;
			}
            
			k--;
			root = sTree.top()->right;
			if (k == 0)
				return sTree.top()->val;
			sTree.pop();
		}
		return -1;
	}
};