class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> dic;
        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            if (dic.find(key) == dic.end()) {
                dic[key] = 1;
            } else {
                dic[key]++;
            }
        }
        priority_queue<pair<int,int>> pq;
        for (auto iter = dic.begin(); iter != dic.end(); iter++) {
            int key = iter->first;
            int val = iter->second;
            pq.push({val,key});
        }
        vector<int> ans; 
        for (int i = 0; i < k; i++) {
            auto curr = pq.top();
            ans.push_back(curr.second);
            pq.pop();
        }
        return ans;
    }
};