class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0; 
        vector<bool> dp(n,true); 
        dp[0] = false;
        dp[1] = false;
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (dp[i] == false) continue;
            if (dp[i] == true) {
                cnt++; 
                int temp = i*2;
                int diff = i;
                while (temp < n) {
                    dp[temp] = false;
                    temp += diff;
                }
            }
        }
        return cnt;
    }
};