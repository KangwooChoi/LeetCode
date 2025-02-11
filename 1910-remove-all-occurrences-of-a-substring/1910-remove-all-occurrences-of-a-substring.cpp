class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> stk;
        int strLength = s.length();
        int partLength = part.length();

        // Iterate through each character in the string
        for (int index = 0; index < strLength; index++) {
            // Push current character to stack
            stk.push(s[index]);

            // If stack size is greater than or equal to the part length, check
            // for match
            if (stk.size() >= partLength && checkMatch(stk, part, partLength)) {
                // Pop the characters matching 'part' from the stack
                for (int j = 0; j < partLength; j++) {
                    stk.pop();
                }
            }
        }

        // Convert stack to string with correct order
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }

        return result;
    }

private:
    // Helper function to check if the top of the stack matches the 'part'
    bool checkMatch(stack<char>& stk, string& part, int partLength) {
        stack<char> temp = stk;

        // Iterate through part from right to left
        for (int partIndex = partLength - 1; partIndex >= 0; partIndex--) {
            // If current stack top doesn't match expected character
            if (temp.top() != part[partIndex]) {
                return false;
            }
            temp.pop();
        }
        return true;
    }
};
//class Solution {
//public:
//    string removeOccurrences(string s, string part) {
//        stack<char> ss, sp;
//        for (int i = 0; i < part.length(); i++) {
//            sp.push(part[i]);
//        }
//        for (int p = 0; p < s.length(); p++) {
//            ss.push(s[p]);
//            if (ss.top() == sp.top()) {
//                ss = remove(ss, sp);
//            }
//        }
//        string ans = "";
//        while (!ss.empty()) {
//            ans = ss.top() + ans;
//            ss.pop();
//        }
//        return ans;
//    }
//    stack<char> remove(stack<char> ss, stack<char> sp) {
//        int n = sp.size();
//        stack<char> sp_org = sp;
//        stack<char> ss_org = ss;
//        while (!ss.empty()) {
//            for (int i = 0; i < n; i++) {
//                if (!ss.empty() && ss.top() == sp.top()) {
//                    ss.pop();
//                    sp.pop();
//                } else {
//                    break;
//                }
//            } 
//            if (!sp.empty()) break;
//            ss_org = ss;
//        }
//        return ss_org;
//    }
//};