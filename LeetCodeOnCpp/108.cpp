#include "head_file.h"

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
    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end) {
        if (end <= start)
            return nullptr;
        int midIdx = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[midIdx]);
        root->left = sortedArrayToBST(nums, start, midIdx);
        root->right = sortedArrayToBST(nums, midIdx + 1, end);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};