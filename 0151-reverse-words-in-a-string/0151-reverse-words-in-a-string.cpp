class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stack<string> st;
        istringstream is(s);
        string word;
        while (getline(is, word, ' ')) {
            if (word.length() != 0) {
                st.push(word);
            }
        }
        while (!st.empty()) { 
            string curr = st.top();
            st.pop();
            if (curr.length() != 0) ans += curr + ' ';
        }
        return ans.substr(0, ans.length()-1);
    }
};
//class Solution {
//public:
//    string reverseWords(string s) {
//        stack<string> st;
//        char delimiter = ' ';
//        string word = "";
//        for (int i = 0; i < s.length(); i++) {
//            if (s[i] == delimiter) {
//                if (word.length() != 0) st.push(word);
//                word = "";
//                continue;
//            }
//            word += s[i];
//        } 
//        if (word.length() != 0) st.push(word);
//        string ans = "";
//        while (!st.empty()) {
//            ans += st.top() + ' ';
//            st.pop(); 
//        }
//        return ans.substr(0,ans.length()-1);
//    }
//};