class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int cnt = 0;
        string temp = "";
        vector<string> ans;
        for (char c : s) {
            cnt++;
            temp.push_back(c);
            if (cnt == k) {
                ans.push_back(temp); 
                temp = "";
                cnt = 0;
            }
        }
        if (temp.length() != 0) {
            int remains = k - temp.length();
            for (int i = 0; i < remains; i++) {
                temp.push_back(fill);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};