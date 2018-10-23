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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        ListNode *new_head = new ListNode(0);
        new_head->next = head;

        ListNode *iter = new_head;
        ListNode *scan = iter->next;
        ListNode *scan_prev = iter;

        while (scan && scan->next) {
            ListNode *tmp = scan;
            while (tmp) {
                if (tmp->val != scan->val) {
                    break;
                }
                tmp = tmp->next;
            }
            if (tmp == scan->next) {
                scan_prev = scan;
                scan = scan->next;
            } else {
                ListNode *deleteNode = scan;
                while (deleteNode != tmp) {
                    ListNode *t = deleteNode->next;
                    delete deleteNode;
                    deleteNode = t;
                }
                scan = tmp;
                scan_prev->next = scan;
            }
        }
        return new_head->next;
    }
};