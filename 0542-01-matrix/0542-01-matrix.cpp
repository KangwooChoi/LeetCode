class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        vector<vector<bool>> seen(m, vector<bool>(n,false));
        queue<vector<int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = mat[i][j];
                if(ans[i][j] == 0) {
                    seen[i][j] = true;
                    q.push({i,j,0});
                }
            }
        }

        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int row = curr[0], col = curr[1], step = curr[2];
            for (auto dir : dirs) {
                int nextRow = row + dir[0], nextCol = col + dir[1];
                if (valid(nextRow, nextCol, m, n) && !seen[nextRow][nextCol]) {
                    seen[nextRow][nextCol] = true;
                    q.push({nextRow, nextCol, step+1});
                    ans[nextRow][nextCol] = step+1; 
                }
            }
        }
        return ans; 
    }
    bool valid(int x, int y, int m, int n) {
        return (0<= x && x < m && 0 <= y && y < n);
    }
};