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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> rets;
        vector<int> ret;
        findPath(root, sum, ret, rets);
        return rets;
    }

private:
    void findPath(TreeNode *node, int sum, vector<int> &ret, vector<vector<int>> &rets) {
        if (node == nullptr)
            return;
        ret.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && sum == node->val)
            rets.push_back(ret);
        findPath(node->left, sum - node->val, ret, rets);
        findPath(node->right, sum - node->val, ret, rets);
        ret.pop_back();
    }
};