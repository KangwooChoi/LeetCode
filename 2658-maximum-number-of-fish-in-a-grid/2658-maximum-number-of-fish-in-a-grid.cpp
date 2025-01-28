class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        int m = grid.size(), n = grid[0].size();
        vector<bool> visited(m*n, false);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[n*i+j] == false && grid[i][j] > 0) {
                    queue<pair<int,int>> q;
                    visited[i*n+j] = true;
                    q.push({i,j});
                    int ret = 0;
                    while (!q.empty()) {
                        int size = q.size();
                        for (int k = 0; k < size; k++) {
                            pair<int,int> curr = q.front();
                            q.pop();
                            ret += grid[curr.first][curr.second];
                            for (int l = 0; l < 4; l++) {
                                int nx = curr.first + dx[l];
                                int ny = curr.second + dy[l];
                                if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] > 0 && visited[nx*n+ny] == false) {
                                    visited[nx*n+ny] = true;
                                    q.push({nx,ny});
                                }
                            }
                        }
                    }
                    ans = max(ans, ret);
                }
                visited[n*i+j] = true;
            }
        }
        return ans;
    }
};