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
		TreeLinkNode *cur, *tail, *head;
		cur = root;
		head = tail = nullptr;
		while (cur != nullptr) {
			if (cur->left != nullptr)
				if (tail != nullptr)
					tail = tail->next = cur->left;
				else
					head = tail = cur->left;

			if (cur->right != nullptr)
				if (tail != nullptr)
					tail = tail->next = cur->right;
				else
					head = tail = cur->right;
			if (!(cur = cur->next)) {
				cur = head;
				head = tail = nullptr;
			}
		}
	}
};