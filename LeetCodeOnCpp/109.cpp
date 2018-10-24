#include "head_file.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return new TreeNode(head->val);

        ListNode *slow = head;
        ListNode *fast = head->next;
        ListNode *last = slow;

        while (fast && fast->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        last->next = nullptr;
        TreeNode *newTree = new TreeNode(slow->val);

        if (head != slow)
            newTree->left = sortedListToBST(head);
        newTree->right = sortedListToBST(fast);
        return newTree;
    }

    TreeNode *sortedListToBST1(ListNode *head) {
        return sortedListToBST(head, nullptr);
    }

private:
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
        if (head == tail) {
            return nullptr;
        }
        if (head->next == tail) {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }

        ListNode *mid = head, *temp = head;
        while (temp != tail && temp->next != tail) {
            mid = mid->next;
            temp = temp->next->next;
        }
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head, mid);
        root->right = sortedListToBST(mid->next, tail);
        return root;
    }
};