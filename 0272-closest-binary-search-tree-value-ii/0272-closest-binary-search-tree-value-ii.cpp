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
private:
    class MyComparator {
        public:
            MyComparator(double param) : target(param) {}
            bool operator() (const int a, const int b) {
                return std::abs(a-target) < std::abs(b-target);
            }
        private:
            double target;
    };
    void inorder(TreeNode* root, vector<int>& res) const {
        if (root == nullptr) { return; }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> UseHeap(TreeNode* root, double target, int k) const {
        MyComparator comp(target);
        priority_queue<int, vector<int>, MyComparator> heap(comp);

        stack<TreeNode*> stk;
        TreeNode* curr = root;

        // Inorder traversal.
        while (curr != nullptr || !stk.empty()) {
            // Traverse left subtree
            while(curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }

            // Print node
            curr = stk.top();
            stk.pop();
            heap.push(curr->val);
            if (heap.size() > k) { heap.pop(); }

            // Move to right subtree
            curr = curr->right;
        }

        vector<int> res;
        while(!heap.empty()) {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
    vector<int> UseSlidingWindow(TreeNode* root, double target, int k) const {
        vector<int> sorted_values;
        inorder(root, sorted_values);

        if (target <= sorted_values[0]) {
            return vector<int>(sorted_values.begin(), sorted_values.begin()+k);
        } else if (target >= sorted_values.back()) {
            return vector<int>(sorted_values.begin() + sorted_values.size()-k, sorted_values.end());
        }

        // Two pointers
        int left = 0;
        int right = sorted_values.size()-1;
        while (right - left + 1 > k) {
            double left_diff = std::abs(target - sorted_values[left]);
            double right_diff = std::abs(target - sorted_values[right]);
            if (left_diff > right_diff) { left++; }
            else {right--;}
        }
        return vector<int>(sorted_values.begin()+left, sorted_values.begin()+right+1);
    }
public:
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // 1. Use heap
        // O(nlogk), O(N + k) ~ O(N)
        // return UseHeap(root, target, k);

        // 2. Use sliding window
        // O(n), O(n)
        return UseSlidingWindow(root, target, k);
    }
};