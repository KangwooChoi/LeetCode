class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;       
        for (int r=0, c=0, d=1, i=0; i < m*n; i++) {
            ans.push_back(mat[r][c]);
            r -= d, c += d;
            if (r < 0 || r == m || c < 0 || c == n) {
                if (r==m) {
                    r = m - 1;
                    c -= d - 1;
                } 
                if (c==n) {
                    c = n - 1;
                    r += d + 1;
                }
                if (r < 0) {
                    r = 0;
                }
                if (c < 0) {
                    c = 0;
                }
                d = -d;
            }
        }
        return ans;
    }
};