// https://leetcode.com/problems/merge-two-sorted-lists/#/description
// chi zhang, 2017-6-21

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p1 = l1, *p2 = l2, *p = &dummy;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                p->next = p1;
                ListNode* next = p1->next;
                p1->next = nullptr;
                p1 = next;
            } else {
                p->next = p2;
                ListNode* next = p2->next;
                p2->next = nullptr;
                p2 = next;
            }
            p = p->next;
        }
        if (p1 != nullptr) {
            p->next = p1;
        } else if (p2 != nullptr) {
            p->next = p2;
        }
        return dummy.next;
    }
};
