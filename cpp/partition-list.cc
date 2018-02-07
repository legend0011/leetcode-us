// https://leetcode.com/problems/partition-list/description/
// chi zhang, 2017-8-30

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
    ListNode* partition(ListNode* head, int x) {
        ListNode gte(-1);
        ListNode lt(-1);
        ListNode* l = &lt, *r = &gte;
        ListNode* p = head;
        while (p != nullptr) {
            if (p->val < x) {
                l->next = p;
                p = p->next;
                l = l->next;
                l->next = nullptr;
            } else {
                r->next = p;
                p = p->next;
                r = r->next;
                r->next = nullptr;
            }
        }
        l->next = gte.next;
        return lt.next;
    }
};
