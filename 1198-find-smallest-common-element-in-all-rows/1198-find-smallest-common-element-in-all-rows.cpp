class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int> cnts(10001,0);
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (++cnts[mat[i][j]] == m) {
                    return mat[i][j];
                }
            }
        }
        return -1;
    }
};