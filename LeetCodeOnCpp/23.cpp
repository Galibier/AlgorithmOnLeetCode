/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	using iter = vector<ListNode*>::iterator;

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy(INT_MIN);
		ListNode *tail = &dummy;

		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}

	ListNode *mergeK(iter b, iter e) {
		if (b == e)
			return nullptr;

		if (next(b) == e)
			return *b;

		int mid = distance(b, e) / 2;

		ListNode *left = mergeK(b, b + mid);
		ListNode *right = mergeK(b + mid, e);
		return mergeTwoLists(left, right);
	}

public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return mergeK(lists.begin(), lists.end());
	}
};