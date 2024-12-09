class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            while (start < s.size() && !isVowel(s[start])) {
                start++;
            }
            while (end >= 0 && !isVowel(s[end])) {
                end--;
            }
            if (start < end) {
                swap(s[start++], s[end--]);
            }
        }
        return s; 
    }
};