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
    bool flag;
    int total;
    bool checkEqualTree(TreeNode* root) {
        total = sumall(root);
        if(root->left)
            dfs(root->left);
        if(root->right)
            dfs(root->right);
        return flag;
    }
    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        int sum = dfs(root->left) + dfs(root->right) + root->val;
        if(sum == total - sum)
        {
            flag = true;
            return 0;
        }
        return sum;
    }
    int sumall(TreeNode* root)
    {
        if(!root)
            return 0;
        return sumall(root->left) + sumall(root->right) + root->val;
    }
};