class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> freq(n, 0);
        int ans = 0;
        int left = 0;
        int right = 0;
        if (s[0] == '1') freq[0] = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                freq[i] = freq[i-1] + 1;
            } else {
                freq[i] = freq[i-1];
            }
        }
        int one_total = freq[n-1];
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, one_total + i + 1 - 2*freq[i]);
        }
        return ans; 
    }
};