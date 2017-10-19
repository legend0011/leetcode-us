// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* now = head;
        while (now != nullptr) {
            bool need_process = false;
            while (now->next != nullptr &&
                   now->val == now->next->val) {
                now = now->next;
                need_process = true;
            }
            if (need_process) {
                pre->next = now->next;
                now = pre->next;
            } else {
                pre = now;
                now = pre->next;
            }   
        }
        return dummy.next;   
    }
};
