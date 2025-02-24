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
    int ans, low, high;
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->ans = 0;
        this->low = low;
        this->high = high;
        helper(root); 
        return ans;
    }
private:
    void helper(TreeNode* node) {
        if (node == nullptr) return;
        if (node->val >= low && node->val <= high) ans += node->val;
        helper(node->left);
        helper(node->right);
        return;
    }
};