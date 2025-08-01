class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1,1}};
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1,1});
        for (int i = 2; i < numRows; i++) {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 0; j < i - 1; j++) {
                temp.push_back(ans[i-1][j] + ans[i-1][j+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};