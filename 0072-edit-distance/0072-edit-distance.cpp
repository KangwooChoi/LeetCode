class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0)); 
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; i++) {
            dp[0][i] = i;
        }
        for (int row = 1; row <= m; row++) {
            for (int col = 1; col <= n; col++) {
                if (word1[row-1] == word2[col-1]) {
                    dp[row][col] = dp[row-1][col-1];
                } else {
                    dp[row][col] = min({dp[row-1][col], dp[row-1][col-1], dp[row][col-1]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};