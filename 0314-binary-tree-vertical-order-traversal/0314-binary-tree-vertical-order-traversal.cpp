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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q; 
        q.push({root, 99});
        vector<vector<int>> res(199);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            int index = curr.second; 
            if (node == nullptr) continue;
            res[index].push_back(node->val);
            q.push({node->left, index-1});
            q.push({node->right, index+1});
        }
        vector<vector<int>> ans;
        for (auto vec : res) {
            if (vec.size() != 0) {
                ans.push_back(vec); 
            }
        }
        return ans;
    }
};