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
    bool isSymmetric(TreeNode* root) {
        vector<int> leftResult;
        vector<int> rightResult;
        preLeftRight(root->left, leftResult);
        preRightLeft(root->right, rightResult);
        if (leftResult.size() != rightResult.size()) return false;
        for (int i = 0; i < leftResult.size(); i++) {
            if (leftResult[i] != rightResult[i]) return false;
        }
        return true;
    }
private:
    void preLeftRight(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            result.push_back(-101);
            return;
        };
        result.push_back(node->val);
        preLeftRight(node->left, result);
        preLeftRight(node->right, result);
    }
    void preRightLeft(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            result.push_back(-101);
            return;
        };
        result.push_back(node->val);
        preRightLeft(node->right, result);
        preRightLeft(node->left, result);

    }
};