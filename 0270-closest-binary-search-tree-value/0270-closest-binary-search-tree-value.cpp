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
    int closestValue(TreeNode* root, double target) {
        vector<int> vals;
        while (root != nullptr) {
            vals.push_back(root->val);
            if (root->val == target) return root->val;
            else if (root->val < target) root = root->right;
            else if (root->val > target) root = root->left;
        }
        int ans = vals[0]; 
        double diff = abs(target-vals[0]);
        for (int i = 0; i < vals.size(); i++) {
            double new_diff = abs(target-(double)vals[i]);
            if (diff > new_diff) {
                diff = new_diff;
                ans = vals[i];
            } else if (diff == new_diff && ans > vals[i]) {
                diff = new_diff;
                ans = vals[i];
            }
        }
        return ans;
    }
};
//class Solution {
//public:
//    int closest;
//    int closestValue(TreeNode* root, double target) {
//        closest = INT_MAX;
//        helper(root, target);
//        return closest;
//    }
//private:
//    void helper(TreeNode* node, double target) {
//        if (node == nullptr) return;
//        if (abs(node->val-target) < abs(closest-target)) {
//            closest = node->val;
//        } else if (abs(node->val-target) == abs(closest-target) && node->val < closest) {
//            closest = node->val;
//        }
//        if (node->val == target) {
//            return;
//        } else if (node->val > target) {
//            helper(node->left, target);
//        } else {
//            helper(node->right, target);
//        }
//
//    }
//};