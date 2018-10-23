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
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *lhead, *ltail;
        ListNode *ghead, *gtail;
        lhead = ltail = nullptr;
        ghead = gtail = nullptr;

        while (head != nullptr) {
            if (head->val < x) {
                if (lhead == nullptr)
                    lhead = ltail = head;
                else {
                    ltail->next = head;
                    ltail = ltail->next;
                }
            } else {
                if (ghead == nullptr)
                    ghead = gtail = head;
                else {
                    gtail->next = head;
                    gtail = gtail->next;
                }
            }
            head = head->next;
        }

        if (lhead == nullptr)
            return ghead;
        if (ghead == nullptr)
            return lhead;

        ltail->next = ghead;
        gtail->next = nullptr;

        return lhead;
    }
};