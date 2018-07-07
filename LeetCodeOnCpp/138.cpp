/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
class Solution {
public:
	RandomListNode * copyRandomList(RandomListNode *head) {
		if (head == nullptr)
			return nullptr;

		RandomListNode* run = head;
		while (run != nullptr) {
			RandomListNode* copy = new RandomListNode(run->label);
			copy->next = run->next;
			run->next = copy;
			run = run->next->next;
		}

		run = head;
		while (run != nullptr) {
			if (run->random != nullptr)
				run->next->random = run->random->next;
			run = run->next->next;
		}

		RandomListNode* new_head = new RandomListNode(0);
		RandomListNode* new_run;
		run = head;
		new_head->next = head->next;
		while (run != nullptr) {
			new_run = run->next;
			run->next = new_run->next;
			if (run->next)
				new_run->next = new_run->next->next;
			run = run->next;
		}
		return new_head->next;
	}
};