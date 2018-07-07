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
	ListNode * oddEvenList(ListNode *head) {
		if (head == nullptr)
			return head;

		ListNode *odd = head, *evenhead = head->next, *even = evenhead;
		while (even != nullptr&&even->next != nullptr) {
			odd->next = odd->next->next;
			even->next = even->next->next;
			odd = odd->next;
			even = even->next;
		}
		odd->next = evenhead;
		return head;
	}
};