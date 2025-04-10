class Solution {
public:
    vector<vector<int>> dirs = {{1,-1}, {1,0}, {1,1}, {0,-1}, {0,1}, {-1,-1}, {-1,0}, {-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1; 
        queue<vector<int>> q; 
        grid[0][0] = 2;
        q.push({0,0,1});
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int row = curr[0], col = curr[1], step = curr[2];
            if (row == n-1 && col == n-1) return step;
            for (int k = 0; k < 8; k++) {
                auto dir = dirs[k];
                int nrow = row + dir[0];
                int ncol = col + dir[1];
                if (0 <= nrow && nrow < n && 0 <= ncol && ncol < n) {
                    if (nrow == n-1 && ncol == n-1) return step+1;
                    if (grid[nrow][ncol] == 0) {
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol,step+1});
                    }
                }
            }
        }
        return -1;
    }
};