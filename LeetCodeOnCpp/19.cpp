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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode preHead(0);
        preHead.next = head;
        ListNode *t1 = &preHead, *t2 = head;
        for (int i = 1; i < n; ++i) {
            t2 = t2->next;
        }
        while (t2->next != NULL) {
            t1 = t1->next;
            t2 = t2->next;
        }
        t1->next = t1->next->next;
        return preHead.next;
    }
};