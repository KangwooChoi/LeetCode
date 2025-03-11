class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) dp[i][i+1] = true;
        }
        int diff = 2;
        while (diff < n) {
            for (int i = 0; i < n - diff; i++) {
                if (s[i] == s[i+diff] && dp[i+1][i+diff-1]) {
                    dp[i][i+diff] = true;
                } 
            }
            diff++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j]) ans++;
            }
        }
        return ans;
    }
};