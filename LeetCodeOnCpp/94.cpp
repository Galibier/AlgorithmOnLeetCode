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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode *> stk;
        TreeNode *cur = root;

        while (!stk.empty() || cur != nullptr) {
            if (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            } else {
                TreeNode *pNode = stk.top();
                ret.push_back(pNode->val);
                stk.pop();
                cur = pNode->right;
            }
        }
        return ret;
    }
};