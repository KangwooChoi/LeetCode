/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p->val;
        int qVal = q->val;
        TreeNode* node = root;
        while (node != nullptr) {
            int val = node->val;
            if (pVal > val && qVal > val) {
                node = node->right;
            } else if (pVal < val && qVal < val) {
                node = node->left;
            } else {
                return node;
            }
        } 
        return nullptr;
    }
};