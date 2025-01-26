class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int p1 = 0, p2 = 0;
        string ans = "";
        while (p1 < m || p2 < n) {
            if (p1 < m) {
                ans += word1[p1++];
            }
            if (p2 < n) {
                ans += word2[p2++];
            }
        }
        return ans;
    }
};