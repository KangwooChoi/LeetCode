class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.length(); right++) {
            freq[s[right]]++;
            if (freq[s[right]] < 2) {
                ans = max(ans, right-left+1);
            } else {
                while (freq[s[right]] >= 2) {
                    freq[s[left++]]--;
                }
            }
        } 
        return ans;
    }
};