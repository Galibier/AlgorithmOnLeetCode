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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == nullptr) {
			return ret;
		}
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			auto len = que.size();
			vector<int> level;
			for (int i = 0; i < len; i++) {
				auto tmp = que.front();
				que.pop();
				if (tmp->left)
					que.push(tmp->left);
				if (tmp->right)
					que.push(tmp->right);
				level.push_back(tmp->val);
			}
			ret.push_back(level);
			level.clear();
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};