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
	vector<int> largestValues(TreeNode* root) {
		if (root == nullptr)
			return vector<int>();
		queue<TreeNode*> que;
		vector<int> ans;
		que.push(root);
		while (!que.empty()) {
			int maxOfLine = INT_MIN;
			int count = que.size();
			for (int i = 0; i < count; i++) {
				auto node = que.front();
				que.pop();
				if (node->left)
					que.push(node->left);
				if (node->right)
					que.push(node->right);
				if (maxOfLine < node->val)
					maxOfLine = node->val;
			}
			ans.push_back(maxOfLine);
		}
		return ans;
	}
};