class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss;
        stack<char> st;
        for (char c : s) {
            if (c == '#') {
                if (!ss.empty()) ss.pop();
            } else {
                ss.push(c);
            }
        }
        for (char c : t) {
            if (c == '#') {
                if (!st.empty()) st.pop();
            } else {
                st.push(c);
            }
        }
        while (!ss.empty() && !st.empty()) {
            if (ss.top() != st.top()) return false;
            ss.pop();
            st.pop();
        } 
        if (!ss.empty() || !st.empty()) return false;
        return true;
    }
};