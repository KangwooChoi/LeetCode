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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*> nodes;
        ListNode* node = head;
        while (node) {
            nodes.push_back(node);
            node = node->next;
        }    
        int l = left, r = right;
        while (l < r) {
            swap(nodes[l-1], nodes[r-1]);
            l++;
            r--;
        }
        int n = nodes.size();
        for (int i = 0; i < n - 1; i++) {
            nodes[i]->next = nodes[i+1];
        }
        nodes[n-1]->next = nullptr;
        return nodes[0];
    }
};