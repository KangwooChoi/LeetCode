class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,1));
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        return dp[m-1][n-1];
    }
};
//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        if(m == 1 || n == 1) return 1;
//        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
//    }
//};