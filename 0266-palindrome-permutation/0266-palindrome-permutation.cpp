class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int> freq;
        for (char c : s) {
            freq[c]++;
        } 
        bool existOdd = false; 
        for (auto [c, f] : freq) {
            if (f % 2 != 0) {
                if (existOdd) return false;
                existOdd = true;
            }
        }
        return true;
    }
};