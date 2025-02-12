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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
    int solve(TreeNode* node) {
        if (node == nullptr) return 0; 
        int left = solve(node->left);
        int right = solve(node->right);
        ans = max({ans, node->val + left + right, node->val + left, node->val + right, node->val});
        return max({0, left + node->val, right + node->val, node->val});
    }
};