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
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> que;
		queue<int> level;

		que.push(root);
		level.push(0);

		int m = 0;
		while (que.size()) {
			TreeNode *tmp = que.front(); que.pop();
			int l = level.front(); level.pop();
			if (tmp->left) {
				que.push(tmp->left);
				level.push(l + 1);
			}

			if (tmp->right) {
				que.push(tmp->right);
				level.push(l + 1);
			}

			if (l > m) {
				m = l;
				root = tmp;
			}
		}
		return root->val;
	}
};
