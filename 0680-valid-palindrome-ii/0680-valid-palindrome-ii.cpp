class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while (left < right) {
            if (s[left] != s[right]) {
                return (checkPalindrome(s, left, right-1) || checkPalindrome(s, left+1, right));
            }
            left++;
            right--;
        }   
        return true;
    }
private:
    bool checkPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};