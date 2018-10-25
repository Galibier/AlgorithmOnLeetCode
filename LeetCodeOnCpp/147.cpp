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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *pre = new_head;
        ListNode *cur = head;
        while (cur != nullptr) {
            if (cur->next != nullptr && cur->next->val < cur->val) {
                while (pre->next != nullptr && pre->next->val < cur->next->val)
                    pre = pre->next;
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
                pre = new_head;
            } else
                cur = cur->next;
        }
        ListNode *ret = new_head->next;
        delete new_head;
        return ret;
    }
};