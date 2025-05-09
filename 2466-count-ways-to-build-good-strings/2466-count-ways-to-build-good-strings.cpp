class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0);
        dp[one] += 1;
        dp[zero] += 1;
        int modulo = 1e9 + 7;
        for (int i = 1; i < high + 1; i++) {
            if (i > zero) dp[i] += dp[i-zero];
            if (i > one) dp[i] += dp[i-one];
            dp[i] %= modulo;
        }
        int ans = 0;
        for (int i = low; i < high + 1; i++) {
            //cout << dp[i] << endl;
            ans += dp[i];
            ans %= modulo;
        }
        return ans;
    }
};