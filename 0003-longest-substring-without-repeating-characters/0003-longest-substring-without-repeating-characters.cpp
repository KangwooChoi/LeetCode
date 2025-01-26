class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq; 
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.length(); right++){
            if (freq.find(s[right]) == freq.end()) {
                freq[s[right]] = 1;
            } else {
                freq[s[right]]++;
            }
            if (freq[s[right]] > 1) {
                while (freq[s[right]] > 1) {
                    freq[s[left]]--;        
                    left++;
                }
            }
            ans = max(ans, right-left+1);
        } 
        return ans;
    }
};