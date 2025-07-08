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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        while (root != nullptr) {
            if (p->val >= root->val) {
                root = root->right;
            } else {
                ans = root; 
                root = root->left;
            }
        }
        return ans;
    }
};
//class Solution {
//public:
//    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//        vector<TreeNode*> arr;
//        helper(root, arr);
//        int key = p->val;
//        int ans = -1;
//        for (int i = 0; i < arr.size() - 1; i++) {
//            if (arr[i]->val == key) {
//                ans = i + 1;
//                break;
//            }
//        }
//        return ans != -1 ? arr[ans] : nullptr;
//    }
//    
//    void helper(TreeNode* node, vector<TreeNode*>& arr) {
//        if (node == nullptr) return;
//        if (node->left) helper(node->left, arr);
//        arr.push_back(node);
//        if (node->right) helper(node->right, arr);
//        return;
//    }
//};