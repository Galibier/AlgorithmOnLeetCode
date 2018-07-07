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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> rets;
		if (root == nullptr)
			return rets;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int len = q.size();
			vector<int> level;
			for (int i = 0; i < len; i++) {
				auto tmp = q.front();
				q.pop();
				level.push_back(tmp->val);
				if (tmp->left != nullptr)
					q.push(tmp->left);
				if (tmp->right != nullptr)
					q.push(tmp->right);
			}
			rets.push_back(level);
		}

		for (int i = 1; i < rets.size(); i += 2)
			reverse(rets[i].begin(), rets[i].end());
		return rets;
	}
};