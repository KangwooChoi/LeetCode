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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraverse(root, inorder);
        int size = inorder.size();
        return create(inorder, 0, size-1); 
    }
private:
    void inorderTraverse(TreeNode* node, vector<int>& inorder) {
        if (node == nullptr) return;
        inorderTraverse(node->left, inorder);
        inorder.push_back(node->val);
        inorderTraverse(node->right, inorder);
    }

    TreeNode* create(const vector<int>& inorder, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* left = create(inorder, start, mid - 1);
        TreeNode* right = create(inorder, mid + 1, end);
        return new TreeNode(inorder[mid], left, right);
    }
};