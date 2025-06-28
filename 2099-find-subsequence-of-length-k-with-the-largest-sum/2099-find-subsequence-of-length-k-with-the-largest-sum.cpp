class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        vector<int> idx;
        while (k > 0) {
            pair<int,int> temp = pq.top();
            idx.push_back(temp.second);
            pq.pop();
            k--;
        }
        sort(idx.begin(), idx.end());
        vector<int> ans;
        for (int i = 0; i < idx.size(); i++) {
            ans.push_back(nums[idx[i]]);
        }
        return ans;
    }
};