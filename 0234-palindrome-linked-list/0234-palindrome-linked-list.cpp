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
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        vals.push_back(head->val); 
        ListNode* next = head->next;
        while (next) {
            vals.push_back(next->val);
            next = next->next;
        }
        next = head;  
        for (int i = vals.size()-1; i >= 0; i--) {
            if (next->val != vals[i]) return false;
            next = next->next; 
        } 
        return true;
    }
};