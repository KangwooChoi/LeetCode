class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) return helper(s, left+1, right) || helper(s, left, right-1);
            left++, right--;
        } 
        return true;
    }
private:
    bool helper(string s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};