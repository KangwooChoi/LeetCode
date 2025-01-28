class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        vector<int> loc(26,-1);
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            freq[c-'a']++;
            if (loc[c-'a'] == -1) loc[c-'a'] = i;
        }
        int ans = s.length(); 
        for (int j = 0; j < 26; j++) {
            if (freq[j] == 1) {
                ans = min(ans, loc[j]);
            }
        }
        if (ans != s.length()) return ans;
        return -1;
    }
};