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
    vector<int> preorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return vector<int>();
        }
        vector<int> result;
        stack<TreeNode *> treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            auto tmp = treeStack.top();
            result.push_back(tmp->val);
            treeStack.pop();
            if (tmp->right != nullptr)
                treeStack.push(tmp->right);
            if (tmp->left != nullptr)
                treeStack.push(tmp->left);
        }
        return result;
    }
};