class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int twice = 0, missing = 0;
        int n = grid.size();
        vector<bool> existed(n*n+1,false);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int num = grid[i][j];
                if (existed[num]) {
                    twice = num;
                    continue;
                }
                existed[num] = true;
            }
        } 
        for (int k = 1; k <= n*n; k++) {
            if (existed[k] == false) {
                missing = k;
                break;
            }
        }
        return {twice, missing};
    }
};