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
        vector<vector<int>> result;
        vector<int> ans;
        // BFS
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> intermediate;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                intermediate.push_back(curr->val); 
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            } 
            result.push_back(intermediate);
        } 
        for (auto inter : result) {
            ans.push_back(inter.back());
        }
        return ans;
    }
};