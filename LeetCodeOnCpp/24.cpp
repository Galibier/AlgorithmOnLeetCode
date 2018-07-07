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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* ret = head->next;
		head->next = swapPairs(ret->next);
		ret->next = head;

		return ret;
    }
};