class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          grid[r][c] = '0'; // mark as visited
          queue<pair<int, int>> neighbors;
          neighbors.push({r, c});
          while (!neighbors.empty()) {
            auto rc = neighbors.front();
            neighbors.pop();
            int row = rc.first, col = rc.second;
            if (row - 1 >= 0 && grid[row-1][col] == '1') {
              neighbors.push({row-1, col}); grid[row-1][col] = '0';
            }
            if (row + 1 < nr && grid[row+1][col] == '1') {
              neighbors.push({row+1, col}); grid[row+1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col-1] == '1') {
              neighbors.push({row, col-1}); grid[row][col-1] = '0';
            }
            if (col + 1 < nc && grid[row][col+1] == '1') {
              neighbors.push({row, col+1}); grid[row][col+1] = '0';
            }
          }
        }
      }
    }

    return num_islands;
  }
};
//class Solution {
//public:
//    int dx[4] = {1, -1, 0, 0};
//    int dy[4] = {0, 0, 1, -1};
//
//    int numIslands(vector<vector<char>>& grid) {
//        int ans = 0;
//        int m = grid.size(), n = grid[0].size();
//        queue<pair<int,int>> q;
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == '1') {
//                    ans++;
//                    q.push({i,j});
//                    while (!q.empty()) {
//                        int size = q.size();
//                        for (int s = 0; s < size; s++) {
//                            auto curr = q.front();
//                            grid[curr.first][curr.second] = '2';
//                            q.pop();
//                            for (int k = 0; k < 4; k++) {
//                                int nx = curr.first + dx[k];
//                                int ny = curr.second + dy[k];
//                                if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] == '1') {
//                                    q.push({nx,ny});
//                                }
//                            }
//                        }
//                    }
//                } 
//            }
//        }
//        return ans; 
//    }
//};