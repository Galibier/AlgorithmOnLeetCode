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
	vector<int> findFrequentTreeSum(TreeNode* root) {
		unordered_map<int, int> countNum;
		int maxCount = 0;
		countSubTreeSum(countNum, root, maxCount);

		vector<int> ans;
		for (auto item : countNum) {
			if (item.second == maxCount)
				ans.push_back(item.first);
		}
		return ans;
	}

	int countSubTreeSum(unordered_map<int, int> &countNum, TreeNode* root, int &maxCount) {
		if (root == nullptr)
			return 0;
		int sum = root->val;
		sum += countSubTreeSum(countNum, root->left, maxCount);
		sum += countSubTreeSum(countNum, root->right, maxCount);
		++countNum[sum];
		maxCount = max(maxCount, countNum[sum]);
		return sum;
	}
};