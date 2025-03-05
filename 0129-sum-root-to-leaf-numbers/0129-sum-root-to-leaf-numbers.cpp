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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int result = 0;
        helper(root, result, ans);
        return ans; 
    }
private:
    void helper(TreeNode* node, int result, int& ans) {
        if (node->left == nullptr && node->right == nullptr) ans += result + node->val;
        if (node->left) helper(node->left, (result+node->val)*10, ans); 
        if (node->right) helper(node->right, (result+node->val)*10, ans); 
    }
};