class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        for (char c : s) {
            freq[c-'a']++;
        }
        int odd = 0;
        int even = 100;
        for (int f : freq) {
            if (f == 0) continue;
            if (f % 2 == 0) {
                even = min(even, f);
            } else {
                odd = max(odd, f);
            }
        } 
        return odd - even;
    }
};