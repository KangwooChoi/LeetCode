/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_route = DFS(root, p, {}); 
        vector<TreeNode*> q_route = DFS(root, q, {}); 
        int m = p_route.size(), n = q_route.size(); 
        int ans = 0;
        while (ans < m && ans < n) {
            if (p_route[ans] != q_route[ans]) return p_route[--ans]; 
            ans++;
        }
        return p_route[--ans];
    }
private:
    vector<TreeNode*> DFS(TreeNode* node, TreeNode* target, vector<TreeNode*> route) {
        if (node == nullptr) return {};
        route.push_back(node);
        if (node->val == target->val) return route;
        vector<TreeNode*> ret_left = DFS(node->left, target, route);
        vector<TreeNode*> ret_right = DFS(node->right, target, route);
        if (ret_left.size() != 0) return ret_left;
        if (ret_right.size() != 0) return ret_right;
        return {};
    } 
};