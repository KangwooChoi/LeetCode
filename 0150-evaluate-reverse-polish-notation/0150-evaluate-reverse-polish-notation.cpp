class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) return stoi(tokens[0]);
        stack<int> st;
        st.push(stoi(tokens[0]));
        st.push(stoi(tokens[1]));
        for (int i = 2; i < tokens.size(); i++) {
            string t = tokens[i];
            if (t == "+" || t == "-" || t == "*" || t == "/" ) {
                int r = st.top();
                st.pop();
                int l = st.top();
                st.pop();
                if (t == "+") st.push(l+r);
                else if (t == "-") st.push(l-r);
                else if (t == "*") st.push(l*r);
                else if (t == "/") st.push(l/r);
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};