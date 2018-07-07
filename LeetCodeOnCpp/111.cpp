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
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		queue<pair<TreeNode*, int>> que;
		int depth = 1;
		que.push(make_pair(root, depth));
		while (!que.empty()) {
			auto tmp = que.front();
			depth = tmp.second;
			que.pop();
			if (tmp.first->left == nullptr&&tmp.first->right == nullptr)
				break;
			if (tmp.first->left)
				que.push(make_pair(tmp.first->left, depth + 1));
			if (tmp.first->right)
				que.push(make_pair(tmp.first->right, depth + 1));
		}
		return depth;

	}
};