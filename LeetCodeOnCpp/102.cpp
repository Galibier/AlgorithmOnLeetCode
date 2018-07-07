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
	vector<vector<int>> levelOrder(TreeNode *root) {
		vector<vector<int>> ret;
		if (root==nullptr) 
			return ret;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> tmp_vec;
			int n = q.size();
			for (int i = 0; i < n; i++) {
				TreeNode* t = q.front();
				q.pop();
				tmp_vec.push_back(t->val);
				if (t->left!=nullptr) q.push(t->left);
				if (t->right!=nullptr) q.push(t->right);
			}
			ret.push_back(tmp_vec);
		}
		return ret;
	}
};