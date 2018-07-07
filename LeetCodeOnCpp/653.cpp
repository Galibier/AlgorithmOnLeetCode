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
	bool findTarget(TreeNode* root, int k) {
		vector<int> nums;
		search(root, nums);
		return twoSum(nums, k);
	}
private:
	void search(TreeNode* root, vector<int> &nums) {
		if (root == nullptr) {
			return;
		}
		search(root->left, nums);
		nums.push_back(root->val);
		search(root->right, nums);
	}

	bool twoSum(vector<int>& nums, int target) {
		int index1 = 0, index2 = nums.size() - 1;

		while (index1 < index2) {
			if (nums[index1] + nums[index2] > target) index2--;
			else if (nums[index1] + nums[index2] < target) index1++;
			else return true;
		}
		return false;
	}
};