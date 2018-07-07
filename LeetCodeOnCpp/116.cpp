/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == nullptr)
			return;
		TreeLinkNode *pre = root;
		TreeLinkNode *cur = nullptr;
		while (pre->left != nullptr) {
			cur = pre;
			while (cur) {
				cur->left->next = cur->right;
				if (cur->next)
					cur->right->next = cur->next->left;
				cur = cur->next;
			}
			pre = pre->left;
		}
	}
};