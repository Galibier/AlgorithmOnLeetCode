#include "head_file.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs_recursive(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *ret = head->next;
        head->next = swapPairs(ret->next);
        ret->next = head;

        return ret;
    }

    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *first = head, *second = head->next;
        while (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
            if (first->next) first = first->next->next;
            if (second->next) second = second->next->next;
        }
        return head;
    }
};