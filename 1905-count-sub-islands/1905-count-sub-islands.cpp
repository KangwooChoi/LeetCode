class Solution {
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isCellLand(int x, int y, vector<vector<int>>& grid) {
        return grid[x][y] == 1;
    }

public:
    bool isSubIsland(int x, int y, vector<vector<int>>& grid1,
                     vector<vector<int>>& grid2,
                     vector<vector<bool>>& visited) {
        int totalRows = grid2.size();
        int totalCols = grid2[0].size();

        int isSubIsland = true;

        queue<pair<int, int>> pendingCells;
        pendingCells.push({x, y});
        visited[x][y] = true;

        while (!pendingCells.empty()) {
            int curr_x = pendingCells.front().first;
            int curr_y = pendingCells.front().second;
            pendingCells.pop();

            if (!isCellLand(curr_x, curr_y, grid1)) {
                isSubIsland = false;
            }
            for (auto& direction : directions) {
                int next_x = curr_x + direction[0];
                int next_y = curr_y + direction[1];
                if (next_x >= 0 && next_y >= 0 && next_x < totalRows &&
                    next_y < totalCols && !visited[next_x][next_y] &&
                    isCellLand(next_x, next_y, grid2)) {
                        pendingCells.push({next_x, next_y});
                        visited[next_x][next_y] = true;
                    }
            }
        }

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int totalRows = grid2.size();
        int totalCols = grid2[0].size();

        vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));
        int subIslandCounts = 0;

        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (!visited[x][y] && isCellLand(x, y, grid2) &&
                    isSubIsland(x, y, grid1, grid2, visited)) {
                    subIslandCounts += 1;
                }
            }
        }
        return subIslandCounts; 
    }
};