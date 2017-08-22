// https://leetcode.com/problems/swap-nodes-in-pairs/#/description
// chi zhang, 2017-6-22

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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* zero = &dummy, *first = head;
        if (first == nullptr) {
            return dummy.next;
        }
        ListNode* second = first->next;
        
        while (second != nullptr) {
            // swap first and second
            ListNode* third = second->next;
            zero->next = second;
            second->next = first;
            first->next = third;
            
            // move pointers
            zero = first;
            first = third;
            if (third == nullptr) {
                break;
            }
            second = third->next;
        }
        return dummy.next;
    }
};
