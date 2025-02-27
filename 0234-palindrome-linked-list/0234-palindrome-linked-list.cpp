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
        vector<int> values;
        helper(head, values); 
        int left = 0, right = values.size()-1;
        while (left < right) {
            if (values[left++] != values[right--]) return false;
        }
        return true;
    }
private:
    void helper(ListNode* node, vector<int>& vals) {
        if (node == nullptr) return;
        vals.push_back(node->val);
        helper(node->next, vals);
    }
};