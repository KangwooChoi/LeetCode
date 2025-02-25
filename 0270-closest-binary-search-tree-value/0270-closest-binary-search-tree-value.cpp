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
    int closest;
    int closestValue(TreeNode* root, double target) {
        closest = INT_MAX;
        helper(root, target);
        return closest;
    }
private:
    void helper(TreeNode* node, double target) {
        if (node == nullptr) return;
        if (abs(node->val-target) < abs(closest-target)) {
            closest = node->val;
        } else if (abs(node->val-target) == abs(closest-target) && node->val < closest) {
            closest = node->val;
        }
        if (node->val == target) {
            return;
        } else if (node->val > target) {
            helper(node->left, target);
        } else {
            helper(node->right, target);
        }

    }
};