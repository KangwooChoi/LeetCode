/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        deque<int> q;
        q.push_back(head->val); 
        ListNode* next = head->next;
        while(next != nullptr) {
            q.push_back(next->val);
            next = next->next;
        }
        int ans = 0;
        while (!q.empty()) {
            int temp = q.front() + q.back();
            ans = max(ans, temp);
            q.pop_back();
            q.pop_front();
        }
        return ans;
    }
};