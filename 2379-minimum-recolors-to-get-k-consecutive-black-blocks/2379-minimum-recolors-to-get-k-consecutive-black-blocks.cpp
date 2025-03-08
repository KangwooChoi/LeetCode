class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        vector<int> freq_wh(n+1,0);
        for (int i = 0; i < n; i++) {
            if (blocks[i] == 'W') {
                freq_wh[i+1] = freq_wh[i] + 1;
            } else freq_wh[i+1] = freq_wh[i]; 
        } 
        int ans = INT_MAX;
        for (int i = k-1; i < n; i++) {
            ans = min(ans, freq_wh[i+1] - freq_wh[i-k+1]);
        }
        return ans;
    }
};