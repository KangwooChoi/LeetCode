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
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> ans;
       if (root == nullptr) return ans;
       helper(root, ans);
       return ans; 
    }
private:
    void helper(TreeNode* node, vector<int>& arr) {
        
        if (node->left != nullptr) helper(node->left, arr);
        if (node->right != nullptr) helper(node->right, arr);
        arr.push_back(node->val);
        return;
    }
};