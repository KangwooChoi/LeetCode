class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for (char c : s) {
            if (isDigit(c)) ans = ans.substr(0,ans.size()-1);
            else ans.push_back(c);
        }
        return ans; 
    }
    bool isDigit(char c) {
        return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
    }
};