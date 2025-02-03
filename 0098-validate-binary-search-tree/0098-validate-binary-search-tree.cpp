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
    bool isValidBST(TreeNode* root) {
        vector<int> vals;
        inorderTraverse(root, vals);
        for (int i = 1; i < vals.size(); i++) {
            if (vals[i-1] >= vals[i]) return false; 
        }
        return true;
   }
private:
    void inorderTraverse(TreeNode* node, vector<int>& vals) {
        if (node == nullptr) return;
        inorderTraverse(node->left, vals);
        vals.push_back(node->val);
        inorderTraverse(node->right, vals);
    }
};
//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//        if (root == nullptr) return true;
//        if (root->left == nullptr && root->right == nullptr) return true;
//        bool retLeft = true;
//        if (root->left) {
//            if (root->left->val >= root->val) return false; 
//            retLeft = isValidBST(root->left);
//        }
//        bool retRight = true;
//        if (root->right) {
//            if (root->right->val <= root->val) return false; 
//            retRight = isValidBST(root->right);
//        }
//        return retLeft && retRight; 
//    }
//};