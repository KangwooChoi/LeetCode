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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,unordered_set<int>> map;
        convert(root, 0, map);
        queue<int> q;
        q.push(start);
        int minute = 0;
        unordered_set<int> visited;
        visited.insert(start);

        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize > 0) {
                int curr = q.front();
                q.pop();

                for (int num : map[curr]) {
                    if (visited.find(num) == visited.end()) {
                        visited.insert(num);
                        q.push(num);
                    }
                }
                levelSize--;
            }
            minute++;
        }
        return minute - 1;
    }
    void convert(TreeNode* curr, int parent, unordered_map<int,unordered_set<int>>& map) {
        if (curr == nullptr) return;
        if (map.find(curr->val) == map.end()) {
            map[curr->val] = unordered_set<int>();
        }
        unordered_set<int>& adjList = map[curr->val];
        if (parent != 0) {
            adjList.insert(parent);
        }
        if (curr->left != nullptr) {
            adjList.insert(curr->left->val);
        }
        if (curr->right != nullptr) {
            adjList.insert(curr->right->val);
        }
        convert(curr->left, curr->val, map);
        convert(curr->right, curr->val, map);
        
    }
};