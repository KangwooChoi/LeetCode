class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = ""; 
        int p1 = 0, p2 = 0;
        int m = word1.length(), n = word2.length();
        while (p1 < m && p2 < n) {
            ans += word1[p1++];
            ans += word2[p2++];
        }
        while (p1 < m) {
            ans += word1[p1++];
        }
        while (p2 < n) {
            ans += word2[p2++];
        }
        return ans;
    }
};