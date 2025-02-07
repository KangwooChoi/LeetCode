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
        vector<vector<int>> res(199);
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;
        if (root == nullptr) return ans;
        q.push({root,99});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                TreeNode* node = curr.first;
                int index = curr.second;
                res[index].push_back(node->val);
                if (node->left != nullptr) {
                    q.push({node->left, index-1});
                }
                if (node->right != nullptr) {
                    q.push({node->right, index+1});
                }
            } 
        }
        for(int i = 0; i < res.size(); i++) {
            if (res[i].size() != 0) ans.push_back(res[i]);
        }
        return ans;
    }
};
//class Solution {
//public:
//    vector<vector<int>> verticalOrder(TreeNode* root) {
//        vector<vector<int>> res(199, vector<int>());
//        inorder(root, 99, res); 
//        vector<vector<int>> ans;
//        for(int i = 0; i < res.size(); i++) {
//            if (res[i].size() != 0) ans.push_back(res[i]);
//        }
//        return ans;
//    }
//private:
//    void inorder(TreeNode* node, int index, vector<vector<int>>& res) {
//        if (node == nullptr) return;
//        res[index].push_back(node->val);
//        inorder(node->left, index - 1, res);
//        inorder(node->right, index + 1, res);
//        return;
//    }
//};