class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] != 0 || grid[m-1][n-1] != 0) return -1;
        queue<vector<int>> q;
        q.push({0,0,1});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                if (curr[0] == m-1 && curr[1] == n-1) return curr[2];
                for (int k = 0; k < 8; k++) {
                    int nx = curr[0] + dir[k][0];
                    int ny = curr[1] + dir[k][1];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        q.push({nx,ny,curr[2]+1});
                    }
                }
            }
        }
        return -1;
    }
};