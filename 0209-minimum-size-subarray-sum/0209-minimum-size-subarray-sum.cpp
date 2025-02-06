class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
            if (dp[i][i] >= target) return 1;
        }
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = dp[i][j-1] + nums[j]; 
                if (dp[i][j] >= target) ans = min(ans, j - i + 1);
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
};