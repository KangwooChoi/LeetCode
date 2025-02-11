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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        ListNode head(0);
        ListNode* p = &head;
        for (ListNode* l : lists) {
            while (l) {
                nodes.push_back(l->val);
                l = l->next;
            }
        } 
        sort(nodes.begin(), nodes.end());
        for (int x : nodes){
            p->next = new ListNode(x);
            p = p->next;
        }
        return head.next;
    }
};