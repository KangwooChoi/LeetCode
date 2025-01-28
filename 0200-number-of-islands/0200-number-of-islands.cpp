class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),false));
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    queue<pair<int,int>> q;
                    q.push({i,j});    
                    visited[i][j] = true;
                    ans++;
                    while (!q.empty()){
                        int size = q.size();
                        for (int l = 0; l < size; l++) {
                            pair<int,int> curr = q.front();
                            q.pop();
                            for (int k = 0; k < 4; k++) {
                                int nx = curr.first + dx[k];
                                int ny = curr.second + dy[k];
                                if (0<= nx && nx < grid.size() && 0 <= ny && ny < grid[0].size() && visited[nx][ny] == false && grid[nx][ny] == '1') {
                                    q.push({nx,ny});
                                    visited[nx][ny] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans; 
    }
};