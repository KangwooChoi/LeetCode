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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        DFS(root, root->val, ans); 
        return ans;
    }
private:
    void DFS(TreeNode* node, int maxNum, int& ans) {
        if (node == nullptr) return;
        if (node->val >= maxNum) ans++;
        DFS(node->left, max(maxNum, node->val), ans);
        DFS(node->right, max(maxNum, node->val), ans);
    }
};