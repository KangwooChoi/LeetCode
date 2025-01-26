class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string temp = "";
            for (int j = 0; j < strs[i].length(); j++) {
                if (ans[j] != strs[i][j]) break;
                temp.push_back(strs[i][j]);
            }
            ans = temp; 
        }
        return ans;
    }
};