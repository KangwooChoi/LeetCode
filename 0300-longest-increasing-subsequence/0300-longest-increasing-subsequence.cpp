class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for (int right = 1; right < n; right++) {
            for (int left = 0; left < right; left++) {
                if (nums[left] < nums[right]) {
                    dp[right] = max(dp[right], dp[left] + 1);
                }
            }
        }
        int ans = 0;
        for (int c : dp) {
            ans = max(ans, c);
        }
        return ans;
    }
};