class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        if (n == 1) return 0;
        for (int x : nums) {
            freq[x]++;
        }
        if (freq.size() == 1) return 0;
        int ans;
        for (auto& [x, f] : freq) {
            if (freq.count(x-1)) ans = max(ans, f + freq[x-1]);
        }
        return ans;
    }
};