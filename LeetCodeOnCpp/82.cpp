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
	ListNode * deleteDuplicates(ListNode* head) {
		if (head == nullptr)
			return 0;
		if (head->next==nullptr)
			return head;

		int val = head->val;
		ListNode *p = head->next;
		if (p->val != val) {
			head->next = deleteDuplicates(p);
			return head;
		}
		else {
			while (p != nullptr&&p->val == val)
				p = p->next;
			return deleteDuplicates(p);
		}
	}
};