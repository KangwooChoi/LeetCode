/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        stack<Node*> p_st;
        stack<Node*> q_st;
        helper(p, p_st); 
        helper(q, q_st); 
        Node* ans = nullptr;
        while (!p_st.empty() && !q_st.empty()) {
            if (p_st.top() == q_st.top()) {
                ans = p_st.top();
                p_st.pop();
                q_st.pop();
            } else {
                break;
            }
        }
        return ans;
    }
private:
    void helper(Node* p, stack<Node*>& st) {
        if (p == nullptr) return;
        st.push(p);
        helper(p->parent, st);
    }
};