class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        /*
        row, col = len(matrix), len(matrix[0])
        dp = [[0] * (col + 1) for _ in range(row + 1)]
        ans = 0
        for i in range(row):
            for j in range(col):
                if matrix[i][j]:
                    dp[i + 1][j + 1] = (
                        min(dp[i][j + 1], dp[i + 1][j], dp[i][j]) + 1
                    )
                    ans += dp[i + 1][j + 1]
        return ans
        */
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(matrix[i][j] == 1) {
                    dp[i + 1][j + 1] =
                        min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
                    ans += dp[i + 1][j + 1];
                }
            }
        }
        return ans;
    }
};