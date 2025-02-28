class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<int> valid;
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            if (s[i] == ')') {
                if (!st.empty()) {
                    valid.push_back(st.top());
                    st.pop();
                    valid.push_back(i);
                }
            }
        }
        sort(valid.begin(), valid.end());
        int p = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')' || s[i] == '(') {
                if (p < valid.size() && i == valid[p]) {
                    ans.push_back(s[i]);
                    p++;
                }
            } else ans.push_back(s[i]);
        }
        return ans; 
    }
};