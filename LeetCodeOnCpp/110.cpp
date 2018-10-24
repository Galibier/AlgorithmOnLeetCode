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
public:
    bool isBalanced(TreeNode *root) {
        return postOrder(root) == -1 ? false : true;
    }

    int postOrder(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};