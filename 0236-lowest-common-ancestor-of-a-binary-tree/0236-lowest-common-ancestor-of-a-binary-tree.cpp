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
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return (left == nullptr) ? right : (right == nullptr) ? left : root;
    }
};

//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        vector<TreeNode*> ans;
//        preorder(root, p, q, ans);
//        return ans[0];
//    }
//private:
//    pair<bool,bool> preorder(TreeNode* node, TreeNode* p, TreeNode* q, vector<TreeNode*>& ans) {
//
//        if (node == nullptr) return {false,false};
//        
//        bool p0 = false, q0 = false;
//        //bool p0 = false, q0 = false, p1 = false, q1 = false, p2 = false, q2 = false;
//        
//        if (node->val == p->val) p0 = true;
//        if (node->val == q->val) q0 = true;
//        
//        auto [p1, q1] = preorder(node->left, p, q, ans);
//        auto [p2, q2] = preorder(node->right, p, q, ans);
//        
//        bool left = p0 || p1 || p2;
//        bool right = q0 || q1 || q2;
//        if (left && right) {
//            ans.push_back(node); 
//        }
//        return {left, right};
//    } 
//};
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        vector<TreeNode*> p_route = DFS(root, p, {}); 
//        vector<TreeNode*> q_route = DFS(root, q, {}); 
//        int m = p_route.size(), n = q_route.size(); 
//        int ans = 0;
//        while (ans < m && ans < n) {
//            if (p_route[ans] != q_route[ans]) return p_route[--ans]; 
//            ans++;
//        }
//        return p_route[--ans];
//    }
//private:
//    vector<TreeNode*> DFS(TreeNode* node, TreeNode* target, vector<TreeNode*> route) {
//        if (node == nullptr) return {};
//        route.push_back(node);
//        if (node->val == target->val) return route;
//        vector<TreeNode*> ret_left = DFS(node->left, target, route);
//        vector<TreeNode*> ret_right = DFS(node->right, target, route);
//        if (ret_left.size() != 0) return ret_left;
//        if (ret_right.size() != 0) return ret_right;
//        return {};
//    } 
//};