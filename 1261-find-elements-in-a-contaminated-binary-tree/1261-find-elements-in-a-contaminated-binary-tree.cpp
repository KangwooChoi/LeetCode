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
class FindElements {
public:
    TreeNode* root;
    
    FindElements(TreeNode* root) {
        DFS(root);
        this->root = root;
    }
    
    bool find(int target) {
        bool ret = findHelper(root, target); 
        return ret;    
    }
private:
    bool findHelper(TreeNode* node, int target) {
        if (node == nullptr) return false;
        if (node->val == target) return true;
        return findHelper(node->left, target) || findHelper(node->right, target); 
    }
    void DFS(TreeNode* node) {
        if (node == nullptr) return;
        if (node->val == -1) {
            node->val = 0;
        }
        if (node->left) {
            node->left->val = node->val * 2 + 1; 
            DFS(node->left);
        }
        if (node->right) {
            node->right->val = node->val * 2 + 2; 
            DFS(node->right);
        }
        return;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */