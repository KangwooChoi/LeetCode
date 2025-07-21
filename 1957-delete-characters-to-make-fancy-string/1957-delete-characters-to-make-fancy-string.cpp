class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int cnt = 1;
        ans.push_back(s[0]);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                cnt++;
                if (cnt >= 3) continue;
            } else {
                cnt = 1;
            }
            ans.push_back(s[i]);
        } 
        return ans;
    }
};