class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        vector<vector<int>> loc(26);
        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            loc[index].push_back(i);
        }
        for (auto v: loc) {
            if (v.size() < 2) continue;
            int start = v[0];
            int end = v[v.size()-1];
            unordered_set<char> between;
            for (int j = start + 1; j < end; j++) {
                between.insert(s[j]);
            }
            ans += between.size();
        }
        return ans;
    }
};