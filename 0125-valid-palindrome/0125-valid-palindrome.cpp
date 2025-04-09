class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char c : s) {
            if (isdigit(c) || isalpha(c)) str.push_back(tolower(c));
        } 
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }
};