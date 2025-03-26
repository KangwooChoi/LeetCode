/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        stack<TreeNode*> st;
        st.push(root);
        helper(st,ans,false);
        return ans;
    }
private:
    void helper(stack<TreeNode*> st, vector<vector<int>>& res, bool isRight) {
        int size = st.size();
        stack<TreeNode*> new_st;
        vector<int> temp;
        for (int i = 0; i < size; i++) {
            temp.push_back(st.top()->val);
            if (isRight) {
                if (st.top()->right) new_st.push(st.top()->right);
                if (st.top()->left) new_st.push(st.top()->left);
            } else {
                if (st.top()->left) new_st.push(st.top()->left);
                if (st.top()->right) new_st.push(st.top()->right);
            }
            st.pop();
        }
        res.push_back(temp);
        if (!new_st.empty()) {
            helper(new_st, res, !isRight);
        }
        return;
    }
};