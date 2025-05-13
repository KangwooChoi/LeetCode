class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26,0);
        vector<long long> nfreq(26,0);
        int INF = 1e9 + 7;
        for (char c : s) {
            freq[c-'a']++;
        }
        for (int i = 0; i < t; i++) {
            for (int k = 0; k < 25; k++) {
                nfreq[k+1] = freq[k];
            }
            nfreq[0] = freq[25] % INF;
            nfreq[1] = (nfreq[1] + freq[25]) % INF;
            for (int k = 0; k < 26; k++) {
                freq[k] = nfreq[k];
            }
        } 
        int ans = 0;
        for (int k = 0; k < 26; k++) {
            ans = (ans + nfreq[k]) % INF;
        }
        return ans;
    }
};