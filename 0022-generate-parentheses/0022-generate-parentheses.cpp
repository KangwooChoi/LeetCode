class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {""};
        }
        vector<string> ans;
        for (int leftCnt = 0; leftCnt < n; leftCnt++) {
            for (string leftStr : generateParenthesis(leftCnt)) {
                for (string rightStr : generateParenthesis(n-1-leftCnt)) {
                    ans.push_back("(" + leftStr + ")" + rightStr);
                }
            }
        }
        return ans;
    }
};