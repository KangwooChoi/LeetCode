class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<long long> sum_to_i(n, 0);
        sum_to_i[0] = nums[0];
        for (int i = 1; i < n; i++) {
            sum_to_i[i] = sum_to_i[i-1] + nums[i];
        } 
        for (int j = 0; j < n - 1; j++) {
            if (sum_to_i[j]*2 >= sum_to_i[n-1]) ans++;
        }
        return ans;
    }
};