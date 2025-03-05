/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<int>> graph;
    vector<int> ans;
    unordered_set<int> visited;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root, nullptr);

        visited.insert(target->val);
        dfs(target->val, 0, k);

        return ans;
    }

private:
    void buildGraph(TreeNode* child, TreeNode* parent) {
        if (child != nullptr && parent != nullptr) {
            graph[child->val].push_back(parent->val);
            graph[parent->val].push_back(child->val);
        }
        if (child->left != nullptr) {
            buildGraph(child->left, child);
        }
        if (child->right != nullptr) {
            buildGraph(child->right, child);
        }
    }

    void dfs(int curr, int dist, int K) {
        if (dist == K) {
            ans.push_back(curr);
            return;
        }
        for (int neighbor : graph[curr]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                dfs(neighbor, dist+1, K);
            }
        }
    }
};