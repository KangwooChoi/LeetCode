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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return nullptr;
        } 

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> currLevelNodes;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                currLevelNodes.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (level % 2 == 1) {
                int left = 0, right = currLevelNodes.size() - 1;
                while (left < right) {
                    int temp = currLevelNodes[left]->val;
                    currLevelNodes[left]->val = currLevelNodes[right]->val;
                    currLevelNodes[right]->val = temp;
                    left++;
                    right--;
                }
            }
            level++;
        }
        return root;
    }
};