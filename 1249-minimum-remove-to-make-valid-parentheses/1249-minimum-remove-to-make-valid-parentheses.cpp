class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> valids;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if(!st.empty()) {
                    valids.insert(st.top());
                    st.pop();
                    valids.insert(i);
                }
            }
        }

        string ans;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == ')') {
                if (valids.find(i) != valids.end()) ans += s[i];
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};