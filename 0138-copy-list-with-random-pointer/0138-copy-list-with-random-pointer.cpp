/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
private:
    unordered_map<Node*,Node*> visitedHash;

public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }        
        if (visitedHash.find(head) != visitedHash.end()) {
            return visitedHash[head];
        }
        Node* node = new Node(head->val, nullptr, nullptr);
        visitedHash[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};
//class Solution {
//private:
//    unordered_map<Node*,Node*> visitedHash;
//
//public:
//    Node* copyRandomList(Node* head) {
//        if (head == NULL) {
//            return NULL;
//        }
//        if (this->visitedHash.find(head) != this->visitedHash.end()) {
//            return this->visitedHash[head];
//        }
//        Node* node = new Node(head->val, NULL, NULL);
//        this->visitedHash[head] = node;
//
//        node->next = this->copyRandomList(head->next);
//        node->random = this->copyRandomList(head->random); 
//        return node;
//    }
//};