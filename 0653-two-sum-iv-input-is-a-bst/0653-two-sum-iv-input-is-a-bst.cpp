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
    bool findTarget(TreeNode* root, int k) {
        vector<int> values;
        inorder(root, values);
        int left = 0, right = values.size() - 1; 
        while (left < right) {
            int total = values[left] + values[right];
            if (total == k) return true;
            if (total > k) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
    void inorder(TreeNode* node, vector<int>& values) {
        if (node->left) inorder(node->left, values);
        values.push_back(node->val);
        if (node->right) inorder(node->right, values);
    }
};