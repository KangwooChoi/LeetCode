class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_cnt = 0;
        int ans = 0;

        for (char c: s) {
            if (c == '(') {
                open_cnt++;
            } else {
                open_cnt > 0 ? open_cnt-- : ans++;
            }
        }
        return open_cnt + ans; 
    }
};