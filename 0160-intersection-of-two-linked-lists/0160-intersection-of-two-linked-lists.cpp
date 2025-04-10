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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        unordered_set<ListNode*> uset;
        while (pA != nullptr) {
            uset.insert(pA);
            pA = pA->next;
        }
        while (pB != nullptr) {
            if (uset.find(pB) != uset.end()) return pB;
            pB = pB->next;
        }
        return nullptr;
    }
};
//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        while (headA != nullptr) {
//            ListNode* pB = headB;
//            while (pB != nullptr) {
//                if (headA == pB) return headA;
//                pB = pB->next;
//            }
//            headA = headA->next;
//        } 
//        return nullptr;
//    }
//};