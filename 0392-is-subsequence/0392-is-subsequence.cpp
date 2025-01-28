class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0;
        for (int i = 0; i < t.length(); i++) {
            if (s[p] == t[i]) p++;
        }
        if (p == s.length()) return true;
        return false; 
    }
};