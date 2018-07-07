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
	ListNode * reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *ret = new ListNode(-1);
		ret->next = head;
		ListNode* pre = ret;
		ListNode* cur = head;
		while (head != nullptr&&head->next != nullptr) {
			ListNode* tmp = pre->next;
			pre->next = cur->next;
			cur->next = cur->next->next;
			pre->next->next = tmp;
		}
		return ret->next;
	}
};