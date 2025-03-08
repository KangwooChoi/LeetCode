class Solution {
public:
    int characterReplacement(string s, int k) {
        string criteria = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int ans = 0;
        for (char c : criteria) {
            int cnt = 0;
            int left = 0, right = 0;
            while (right < s.length()) {
                if (s[right] != c) cnt++;
                while (cnt > k) {
                    if (s[left] != c) cnt--;
                    left++;
                    if (left == right) break;

                }
                ans = max(ans, right-left+1);
                right++;
            }
        }
        return ans; 
    }
};