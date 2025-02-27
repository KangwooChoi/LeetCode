class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                ans[col][row] = matrix[row][col]; 
            }
        }
        return ans;
    }
};