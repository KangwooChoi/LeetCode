class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}}; 
        if (numRows == 2) return {{1}, {1,1}}; 
        vector<vector<int>> ans; 
        for (int i = 0; i < numRows; i++) {
            ans.push_back(vector<int>(i+1,1));
        }
        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};