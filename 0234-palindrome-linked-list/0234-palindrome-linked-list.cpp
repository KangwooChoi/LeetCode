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
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverse(slow); 
        while (rev != nullptr) {
            if (head->val != rev->val) return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
private:
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};