class Solution {
private:
    int exploreIsland(vector<vector<int>>& grid, int islandId, int currentRow,
                      int currentColumn) {
        if (currentRow < 0 || currentRow >= grid.size() || currentColumn < 0 ||
            currentColumn >= grid[0].size() ||
            grid[currentRow][currentColumn] != 1)
            return 0;

        grid[currentRow][currentColumn] = islandId;
        return 1 +
               exploreIsland(grid, islandId, currentRow + 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow - 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow, currentColumn + 1) +
               exploreIsland(grid, islandId, currentRow, currentColumn - 1);
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> islandSizes;
        int islandId = 2;

        // Step 1: Mark all islands and calculate their sizes
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn) {
                if (grid[currentRow][currentColumn] == 1) {
                    islandSizes[islandId] = exploreIsland(
                        grid, islandId, currentRow, currentColumn);
                    ++islandId;
                }
            }
        }

        // If there are no islands, return 1
        if (islandSizes.empty()) {
            return 1;
        }
        // If the entire grid is one island, return its size or size + 1
        if (islandSizes.size() == 1) {
            --islandId;
            return (islandSizes[islandId] == grid.size() * grid[0].size())
                       ? islandSizes[islandId]
                       : islandSizes[islandId] + 1;
        }

        int maxIslandSize = 1;

        // Step 2: Try converting every 0 to 1 and calculate the resulting
        // island size
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn) {
                if (grid[currentRow][currentColumn] == 0) {
                    int currentIslandSize = 1;
                    unordered_set<int> neighboringIslands;

                    // Check down
                    if (currentRow + 1 < grid.size() &&
                        grid[currentRow + 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow + 1][currentColumn]);
                    }

                    // Check up
                    if (currentRow - 1 >= 0 &&
                        grid[currentRow - 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow - 1][currentColumn]);
                    }

                    // Check right
                    if (currentColumn + 1 < grid[0].size() &&
                        grid[currentRow][currentColumn + 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn + 1]);
                    }

                    // Check left
                    if (currentColumn - 1 >= 0 &&
                        grid[currentRow][currentColumn - 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn - 1]);
                    }

                    // Sum the sizes of all unique neighboring islands
                    for (int id : neighboringIslands) {
                        currentIslandSize += islandSizes[id];
                    }

                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        return maxIslandSize;
    }
};
//class Solution {
//private:
//    int dx[4] = {1, -1, 0, 0};
//    int dy[4] = {0, 0, 1, -1};
//public:
//    int largestIsland(vector<vector<int>>& grid) {
//        int n = grid.size();
//        int count = 0;
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++){
//                if (grid[i][j] == 1) count++;
//            }
//        }
//        if (count == n*n) return count;
//        vector<vector<int>> parent(n, vector<int>(n,0));
//        queue<pair<int,int>> q;
//        int p_index = 1;
//        int ans = 0;
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == 1) {
//                    bfs(grid, i, j, parent, p_index);
//                    p_index++;
//                } 
//            }
//        }
//        vector<int> area(p_index, 0);
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                int temp = parent[i][j];
//                if (temp != 0) area[temp]++;
//                ans = max(ans, area[temp]);
//            }
//        }
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == 0) {
//                    set<int> island;
//                    for (int k = 0; k < 4; k++) {
//                        int nx = i + dx[k];
//                        int ny = j + dy[k];
//                        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
//                            island.insert(parent[nx][ny]);
//                        }
//                    }
//                    int curr = 0;
//                    for (int no : island) {
//                        curr += area[no];
//                    }
//                    ans = max(ans, curr+1);
//                } 
//            }
//        }
//        return ans;
//    }
//private:
//    void bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& parent, int p_index) {
//        int n = grid.size();
//        queue<pair<int,int>> q;
//        parent[i][j] = p_index;
//        grid[i][j] = 2;
//        for (int k = 0; k < 4; k++) {
//            int nx = i + dx[k]; 
//            int ny = j + dy[k]; 
//            if (0<= nx && nx < n && 0 <= ny && ny < n && grid[nx][ny] == 1) {
//                q.push({nx,ny});
//            }
//        }
//        while (!q.empty()) {
//            int s = q.size(); 
//            for (int k = 0; k < s; k++) {
//                pair<int,int> curr = q.front();
//                q.pop();
//                parent[curr.first][curr.second] = p_index;
//                grid[curr.first][curr.second] = 2;
//                for (int l = 0; l < 4; l++) {
//                    int nx = curr.first + dx[l];
//                    int ny = curr.second + dy[l];
//                    if (0<= nx && nx < n && 0 <= ny && ny < n && grid[nx][ny] == 1) {
//                        q.push({nx,ny});
//                    }
//                }
//            }
//        }
//    }
//};