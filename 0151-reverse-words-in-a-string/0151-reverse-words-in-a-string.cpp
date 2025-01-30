class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stack<string> stack;
        string temp = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (temp != "") {
                    stack.push(temp);
                    temp = "";
                }
            } else {
                temp += s[i];
            }
        }
        if (temp.length() != 0) stack.push(temp);
        while (!stack.empty()) {
            ans += stack.top();
            ans += ' ';
            stack.pop();
        }
        return ans.substr(0,ans.length()-1);
    }
};