// https://leetcode.com/problems/merge-k-sorted-lists/#/description
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        auto cmp = [](pair<ListNode*, size_t> left, pair<ListNode*, size_t> right) {
            return left.first->val > right.first->val;
        };
        std::priority_queue<pair<ListNode*, size_t>, vector<pair<ListNode*, size_t>>, decltype(cmp)> q(cmp);
        // Init heap
        for (size_t i = 0; i < lists.size(); ++i) {
            ListNode* head = lists[i];
            if (head != nullptr) {
                q.push(std::make_pair(head, i));
            }
        }
        // Calculate
        ListNode* p = &dummy;
        while (!q.empty()) {
            // Get top node
            auto item = q.top();
            q.pop();
            ListNode* now = item.first;
            size_t position = item.second;
            ListNode* next = now->next;
            now->next = nullptr;
            lists[position] = next;
            p->next = now;
            p = p->next;
            
            // Push next node
            if (next != nullptr) {
                q.push(std::make_pair(next, position));
            }
        }
        return dummy.next;
    }
};
