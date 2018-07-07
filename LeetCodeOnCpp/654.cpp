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
	TreeNode * constructMaximumBinaryTree(vector<int>& nums) {
		int len = nums.size();
		return insertBinaryTreeNode(nums, 0, len);
	}

	TreeNode* insertBinaryTreeNode(vector<int>& nums, int l, int r) {
		if (l == r)
			return NULL;

		int maxValue = nums[l], index = l;
		for (int i = l + 1; i < r; i++) {
			if (maxValue < nums[i]) {
				maxValue = nums[i];
				index = i;
			}
		}
		TreeNode *head = new TreeNode(maxValue);
		head->left = insertBinaryTreeNode(nums, l, index);
		head->right = insertBinaryTreeNode(nums, index + 1, r);
		return head;
	}
};