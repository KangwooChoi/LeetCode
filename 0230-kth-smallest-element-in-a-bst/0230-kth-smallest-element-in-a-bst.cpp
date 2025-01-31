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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        dfs(root, pq);
        
        while (--k) {
            pq.pop();
        }
        return -pq.top();
    }
private:
    void dfs(TreeNode* node, priority_queue<int>& pq) {
        if (node == nullptr) return;
        pq.push(-node->val);
        if (node->left) dfs(node->left, pq);
        if (node->right) dfs(node->right, pq);
    }
};