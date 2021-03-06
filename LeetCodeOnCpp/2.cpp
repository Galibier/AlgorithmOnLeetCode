/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include "head_file.h"

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode preHead(0), *head = &preHead;
		int carry = 0;
		while (l1 != nullptr || l2 != nullptr || carry != 0) {
			if (l1 != nullptr) {
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) {
				carry += l2->val;
				l2 = l2->next;
			}
			head->next = new ListNode(carry % 10);
			carry /= 10;
			head = head->next;
		}
		return preHead.next;
	}
};