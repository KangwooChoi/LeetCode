class Solution {
public:
    bool isPalindrome(string s) {
        string conv = "";
        for (char c : s) {
            if (isalpha(c) || isdigit(c)) conv.push_back(tolower(c));
        } 
        int left = 0, right = conv.length()-1;
        while (left < right) { 
            if (conv[left++] != conv[right--]) return false;
        }
        return true;
    }
};