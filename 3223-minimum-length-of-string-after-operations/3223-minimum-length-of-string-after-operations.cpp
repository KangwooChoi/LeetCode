class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        for (char c: s) {
            freq[c-'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            if (freq[i] % 2 == 0) {
                ans += 2;
            } else {
                ans += 1;
            }
        } 
        return ans;
    }
};