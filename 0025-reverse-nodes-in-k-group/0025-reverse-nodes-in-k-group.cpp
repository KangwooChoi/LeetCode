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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> nodes;
        ListNode* p = head;
        while (p) {
            nodes.push_back(p);
            p = p->next;
        } 
        int n = nodes.size();
        vector<ListNode*> ans;
        int left = 0;
        while (left + k <= n) {
            for (int i = left + k - 1; i >= left; i--) {
                ans.push_back(nodes[i]);
            } 
            left += k;
        }
        while (left < n) {
            ans.push_back(nodes[left++]);
        }
        for (int i = 0; i < n - 1; i++) {
            ans[i]->next = ans[i+1]; 
        }
        ans[n-1]->next = nullptr;
        return ans[0];
    }
};