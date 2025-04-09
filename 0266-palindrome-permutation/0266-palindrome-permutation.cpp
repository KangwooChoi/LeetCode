class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> freq(26,0);
        for (char c : s) {
            freq[c-'a']++;
        } 
        bool existOdd = false;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                if (existOdd) return false;
                existOdd = true;
            }
        } 
        return true;
    }
};