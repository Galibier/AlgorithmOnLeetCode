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
	void reorderList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return;

		ListNode *head1 = head, *head2 = head->next;
		ListNode *preNode = nullptr, *curNode;
		while (head2 != nullptr && head2->next != nullptr) {
			head1 = head1->next;
			head2 = head2->next->next;
		}
		head2 = head1->next;
		head1->next = nullptr;

		while (head2 != nullptr) {
			curNode = head2->next;
			head2->next = preNode;
			preNode = head2;
			head2 = curNode;
		}

		head2 = preNode;
		head1 = head;
		while (head2) {
			curNode = head1->next;
			head1->next = head2;
			head1 = head1->next;
			head2 = curNode;
		}

		return;
	}
};