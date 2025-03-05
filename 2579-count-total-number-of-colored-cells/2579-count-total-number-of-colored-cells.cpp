class Solution {
public:
    long long coloredCells(int n) {
        vector<long long> dp(n+1,0);
        dp[1] = 1;
        for (int i = 1; i < n; i++) {
            dp[i+1] = dp[i] + i*4;
        }
        return dp[n]; 
    }
};