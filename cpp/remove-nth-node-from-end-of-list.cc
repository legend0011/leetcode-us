// https://leetcode.com/problems/remove-nth-node-from-end-of-list/#/description
// chi zhang, 2017-6-19
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* p = head;
        while (p != nullptr) {
            ++count;
            p = p->next;
        }
        
        if (n > count) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        int now = -1;
        while (pre != nullptr) {
            if (now == count - n - 1) {
                Remove(pre);
                break;
            }
            ++now;
            pre = pre->next;
        }
        head = dummy.next;
        return head;
    }
private:
    void Remove(ListNode* pre) {
        if (pre == nullptr) {
            return;
        }
        ListNode* now = pre->next;
        if (now == nullptr) {
            return;
        }
        pre->next = now->next;
        delete now;
        now = nullptr;
    }
};
