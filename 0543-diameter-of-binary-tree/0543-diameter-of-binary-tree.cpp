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
    int diameter;
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        DFS(root);
        return diameter; 
    }
private:
    int DFS(TreeNode* node){
        if (node == nullptr) return 0;
        int left = DFS(node->left);
        int right = DFS(node->right);
        diameter = max(diameter, left+right);
        return max(left, right) + 1;
    }
};