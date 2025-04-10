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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int temp = -101;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = que.front();
                que.pop();
                temp = curr->val;
                if (curr->left) que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }
            ans.push_back(temp); 
        }
        return ans; 
    }
};