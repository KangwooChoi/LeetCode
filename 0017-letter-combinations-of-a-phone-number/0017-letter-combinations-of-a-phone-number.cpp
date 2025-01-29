class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) return ans;
        string res = "";
        int i = 0;
        letters(digits, i, res, ans);
        return ans;
    }
private:
    void letters(string digit, int i, string res, vector<string>& ans) {
        if (i == digit.size()) {
            ans.push_back(res);
        } else if (digit[i] == '2') {
            letters(digit, i+1, res+'a', ans);
            letters(digit, i+1, res+'b', ans);
            letters(digit, i+1, res+'c', ans);
        } else if (digit[i] == '3') {
            letters(digit, i+1, res+'d', ans);
            letters(digit, i+1, res+'e', ans);
            letters(digit, i+1, res+'f', ans);
        } else if (digit[i] == '4') {
            letters(digit, i+1, res+'g', ans);
            letters(digit, i+1, res+'h', ans);
            letters(digit, i+1, res+'i', ans);
        } else if (digit[i] == '5') {
            letters(digit, i+1, res+'j', ans);
            letters(digit, i+1, res+'k', ans);
            letters(digit, i+1, res+'l', ans);
        } else if (digit[i] == '6') {
            letters(digit, i+1, res+'m', ans);
            letters(digit, i+1, res+'n', ans);
            letters(digit, i+1, res+'o', ans);
        } else if (digit[i] == '7') {
            letters(digit, i+1, res+'p', ans);
            letters(digit, i+1, res+'q', ans);
            letters(digit, i+1, res+'r', ans);
            letters(digit, i+1, res+'s', ans);
        } else if (digit[i] == '8') {
            letters(digit, i+1, res+'t', ans);
            letters(digit, i+1, res+'u', ans);
            letters(digit, i+1, res+'v', ans);
        } else if (digit[i] == '9') {
            letters(digit, i+1, res+'w', ans);
            letters(digit, i+1, res+'x', ans);
            letters(digit, i+1, res+'y', ans);
            letters(digit, i+1, res+'z', ans);
        }
    }
};