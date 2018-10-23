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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n)
            return head;
        int revLength = n - m;
        ListNode preHead(0);
        preHead.next = head;
        ListNode *pre = &preHead;
        while (--m)
            pre = pre->next;

        ListNode *pstart = pre->next;
        while (revLength--) {
            ListNode *p = pstart->next;
            pstart->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }
        return preHead.next;
    }
};