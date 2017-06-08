// https://leetcode.com/problems/add-two-numbers/#/description
// chi zhang, 2017-6-8

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        int promote = 0;
        while (p1 || p2) {
            int val = Add(p1, p2, &promote);
            if (p1 && p2) {
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1) {
                p1 = p1->next;
            } else if (p2) {
                p2 = p2->next;
            }
            p->next = new ListNode(val);
            p = p->next;
        }
        if (promote > 0) {
            p->next = new ListNode(promote);
            p = p->next;
        }
        if (dummy->next) {
            ListNode* rs = dummy->next;
            delete dummy;
            return rs;
        }
        delete dummy;
        return NULL;
    }
private:
    int Add(ListNode* p1, ListNode* p2, int* promote) {
        int a1 = 0, a2 = 0;
        if (p1) {
            a1 = p1->val;
        }
        if (p2) {
            a2 = p2->val;
        }
        int sum = a1 + a2 + *promote;
        *promote = sum / 10;
        return sum % 10;
    }
};
