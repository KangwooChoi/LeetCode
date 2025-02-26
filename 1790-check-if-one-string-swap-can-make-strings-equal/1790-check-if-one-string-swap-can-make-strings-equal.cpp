class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        stack<char> st;
        bool once = false;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                if (st.empty() && !once) {
                    st.push(s1[i]);
                    st.push(s2[i]);
                } else {
                    if (once) return false;
                    once = true;
                    if (st.top() != s1[i]) return false;
                    st.pop();
                    if (st.top() != s2[i]) return false;
                    st.pop();
                }
            } 
        }
        if (!st.empty()) return false;
        return true;
    }
};