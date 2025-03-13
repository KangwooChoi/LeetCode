class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0,1}, {-1,0}, {0,-1}, {1,0}};
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int temp = 4;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] == 1) temp--;
                }
                ans += temp;
            }
        } 
        return ans;
    }
};