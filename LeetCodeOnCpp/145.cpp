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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> node;
        stack<TreeNode *> toVisit;
        TreeNode *cur = root;
        TreeNode *last = nullptr;

        while (cur != nullptr || !toVisit.empty()) {
            if (cur != nullptr) {
                toVisit.push(cur);
                cur = cur->left;
            } else {
                TreeNode *topNode = toVisit.top();
                if (topNode->right != nullptr && last != topNode->right)
                    cur = topNode->right;
                else {
                    node.push_back(topNode->val);
                    last = topNode;
                    toVisit.pop();
                }
            }
        }
        return node;
    }
};