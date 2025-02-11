class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> cumSum (n,0);
        cumSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i-1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (cumSum[i] * 2 >= cumSum[n-1]) ans++;
        }
        return ans;
    }
};