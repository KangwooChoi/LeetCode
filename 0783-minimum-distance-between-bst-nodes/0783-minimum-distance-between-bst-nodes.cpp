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
    int minDiffInBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values); 
        int diff = INT_MAX;
        for (int i = 0; i < values.size(); i++) {
            for (int j = i + 1; j < values.size(); j++) {
                if (i == j) continue;
                diff = min(diff, abs(values[i]-values[j])); 
            }
        }
        return diff;
    }
private:
    void inorder(TreeNode* node, vector<int>& values) {
        if (node == nullptr) return;
        inorder(node->left, values);
        values.push_back(node->val);
        inorder(node->right, values);
    }
};