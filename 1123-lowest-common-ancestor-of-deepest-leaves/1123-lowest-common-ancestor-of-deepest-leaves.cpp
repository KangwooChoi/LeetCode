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
    int maxDepth;
    vector<vector<TreeNode*>> result;

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> route;
        dfs(root, route, 0);    
        if (result.size() > 1) {
            while (result[0].back() != result[1].back()) {
                result[0].pop_back();
                result[1].pop_back();
            }
        }
        return result[0].back(); 
    }

private:
    void dfs(TreeNode* node, vector<TreeNode*> route, int depth) {
        route.push_back(node);
        if (node->left == nullptr && node->right == nullptr) {
            if (depth > maxDepth) {
                maxDepth = depth;
                result.clear();
                result.push_back(route); 

            } else if (depth == maxDepth) {
                result.push_back(route); 
            } 
            return;
        }
        if (node->left) dfs(node->left, route, depth+1);
        if (node->right) dfs(node->right, route, depth+1);
        return;
    }
};