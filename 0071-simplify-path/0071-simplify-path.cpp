class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string word = "";
        for (char c : path) {
            if (c == '/') {
                if (word != "") {
                    if (word == "..") {
                        if (!st.empty()) st.pop();
                        word = "";
                    } else if (word == ".") {
                        word = "";
                    } else {
                        st.push(word);
                        word = "";
                    }
                }
            } else {
                word += c;
            }
        }
        if (!word.empty() && word != "." && word != "..") st.push(word);
        if (word == ".." && !st.empty()) st.pop();
        
        string ans = "";
        while (!st.empty()) {
            ans = '/' + st.top() + ans;
            st.pop();
        }
        if (ans == "") return "/"; 
        return ans;
    }
};
//class Solution {
//public:
//    string simplifyPath(string path) {
//        vector<string> stack;
//        stringstream ss(path);
//        string temp;
//        while (getline(ss, temp, '/')) {
//            if (temp == "..") {
//                if (!stack.empty()) stack.pop_back();
//            } else if (temp != "." && !temp.empty()) {
//                stack.push_back(temp);
//            }
//        }
//        string res = "";
//        for (auto str : stack) res += "/" + str;
//        if (res.empty()) return "/";
//        else return res;
//        
//    }
//};