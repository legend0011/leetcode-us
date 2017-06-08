// https://leetcode.com/problems/add-two-numbers
// fllin, 2017-6-8

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
    ListNode *h1 = l1, *h2 = l2;
    ListNode dummy(-1), *cur = &dummy;
    int carry = 0;

    while(h1 != nullptr || h2 != nullptr) {
      int x = h1 != nullptr ? h1->val : 0;
      int y = h2 != nullptr ? h2->val : 0;
      int sum = x + y + carry;
      carry = sum / 10;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      h1 = h1 != nullptr ? h1->next : nullptr;
      h2 = h2 != nullptr ? h2->next : nullptr;
    }

    if(carry & 0x1) {
      cur->next = new ListNode(carry);
    }
        
    return dummy.next;    
    // TODO(fllin): reuse l1,l2
  }
};
