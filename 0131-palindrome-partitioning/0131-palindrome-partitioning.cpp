class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currVec;
        dfs(ans, s, 0, currVec);
        return ans; 
    }

    void dfs(vector<vector<string>>& res, string& s, int start, vector<string>& currVec) {
        if (start >= s.length()) res.push_back(currVec);
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                currVec.push_back(s.substr(start, end-start+1));
                dfs(res, s, end+1, currVec);
                currVec.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};