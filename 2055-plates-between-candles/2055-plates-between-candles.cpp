class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> leftmost(n,-1); 
        vector<int> rightmost(n,-1);
        vector<int> candlecnt(n,0);
        if (s[0] == '|') candlecnt[0] = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == '|') {
                candlecnt[i] = candlecnt[i-1] + 1;
            } else candlecnt[i] = candlecnt[i-1];
        }
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') {
                while (p <= i) {
                    leftmost[p++] = i;
                }
            }
        }
        p = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (s[j] == '|') {
                while (p >= j) {
                    rightmost[p--] = j;
                }
            }
        }
        vector<int> ans;
        for (auto query : queries) {
            int left = leftmost[query[0]], right = rightmost[query[1]];
            if (left == -1 or right == -1) {
                ans.push_back(0);
                continue;
            }
            int cnt = candlecnt[right] - candlecnt[left] - 1;
            ans.push_back(max(right-left-1-cnt,0));
        }
        return ans;
    }
};