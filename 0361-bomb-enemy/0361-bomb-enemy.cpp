class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int res = 0, rowKills = 0, m = grid.size(), n = grid[0].size();
        vector<int> colKills(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowKills = 0;
                    for (int c = j; c < n && grid[i][c] != 'W'; c++)
                        rowKills += grid[i][c] == 'E';
                }
                if (i == 0 || grid[i - 1][j] == 'W') {
                    colKills[j] = 0;
                    for (int r = i; r < m && grid[r][j] != 'W'; r++)
                        colKills[j] += grid[r][j] == 'E';
                }
                if (grid[i][j] == '0')
                    res = max(res, rowKills + colKills[j]);
            }
        }
        return res;
    }
};