class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        vector<int> ans; 
        for (auto [val, freq] : umap) {
            pq.push({freq,val});
        }
        while (k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};