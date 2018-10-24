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
    int maxPathSum(TreeNode *root) {
        int maxPath = INT_MIN;
        dfsMaxPath(root, maxPath);
        return maxPath;
    }

    int dfsMaxPath(TreeNode *root, int &maxPath) {
        if (root == nullptr)
            return 0;
        int left = max(0, dfsMaxPath(root->left, maxPath));
        int right = max(0, dfsMaxPath(root->right, maxPath));
        maxPath = max(maxPath, left + right + root->val);
        return root->val + max(left, right);
    }
};