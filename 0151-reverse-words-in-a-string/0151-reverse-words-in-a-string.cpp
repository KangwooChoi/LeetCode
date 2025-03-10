class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        char delimiter = ' ';
        string word = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == delimiter) {
                if (word.length() != 0) st.push(word);
                word = "";
                continue;
            }
            word += s[i];
        } 
        if (word.length() != 0) st.push(word);
        string ans = "";
        while (!st.empty()) {
            ans += st.top() + ' ';
            st.pop(); 
        }
        return ans.substr(0,ans.length()-1);
    }
};