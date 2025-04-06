class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> str;
        for (char c : s) {
            if (isalpha(c) || isdigit(c)) str.push_back(tolower(c));
        }
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true; 
    }
};