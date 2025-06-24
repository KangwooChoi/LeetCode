class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<pair<int,int>> keys;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int start = max(0, i - k);
                int end = min(i + k, n - 1);
                keys.push_back({start,end});
            }
        }    
        for (auto [s, e] : keys ) {
            for (int j = s; j <= e; j++) { 
                if (!ans.empty() && ans.back() >= j) continue;
                ans.push_back(j);
            }
        }
        return ans;
    }
};