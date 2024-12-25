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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int levelMax = -2^31-1;
        while (!q.empty()) {
            queue<TreeNode*> temp_q;
            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();
                levelMax = max(levelMax, curr->val);
                if (curr->left) {
                    temp_q.push(curr->left);
                }
                if (curr->right) {
                    temp_q.push(curr->right);
                }
            }
            ans.push_back(levelMax);
            q = temp_q;
            levelMax = -2^31-1;
        }   
        return ans;     
    }
};