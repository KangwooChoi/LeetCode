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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* x_ = nullptr;
        TreeNode* y_ = nullptr;
        while(!q.empty()) {
            int size = q.size();
            unordered_map<int,int> umap;
            for (int i = 0; i < size; i++) {
                TreeNode* parent = q.front();
                q.pop();
                if (parent->left) {
                    q.push(parent->left);
                    umap[parent->left->val] = parent->val;
                    if (parent->left->val == x) {
                        x_ = parent->left;
                    } else if (parent->left->val == y) {
                        y_ = parent->left;
                    }
                }
                if (parent->right) {
                    q.push(parent->right);
                    umap[parent->right->val] = parent->val;
                    if (parent->right->val == x) {
                        x_ = parent->right;
                    } else if (parent->right->val == y) {
                        y_ = parent->right;
                    }
                }
            }
            if (x_ && y_) {
                if (umap[x_->val] != umap[y_->val]) return true;
                return false;
            } else if (x_ || y_) return false;
        }
        return false; 
    }
};