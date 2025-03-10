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
class BSTIterator {
public:
    vector<int> vals;
    int p;

    BSTIterator(TreeNode* root) {
        inorder(root);     
        p = 0;
    }
    
    int next() {
        return vals[p++]; 
    }
    
    bool hasNext() {
        return p < vals.size(); 
    }
private:
    void inorder(TreeNode* root) {
        if (root->left) {
            inorder(root->left); 
        }
        vals.push_back(root->val);
        if (root->right) {
            inorder(root->right); 
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */