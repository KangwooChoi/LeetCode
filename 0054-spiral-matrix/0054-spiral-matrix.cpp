class Solution {
public:
    vector<int> directions[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size(); 
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int row = 0, col = 0;
        int k = 0;
        queue<pair<int,int>> q;
        q.push({row,col});
        while (!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            row = curr.first, col = curr.second;
            ans.push_back(matrix[row][col]);
            visited[row][col] = true;
            int cnt = 0;
            while (cnt < 4) {
                vector<int> dir = directions[k];
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];
                if (0 <= nextRow && nextRow < m && 0 <= nextCol && nextCol < n && visited[nextRow][nextCol] == false) {
                    q.push({nextRow, nextCol});
                    break;
                } else {
                    cnt++;
                    k++;
                    k %= 4;
                }
            }
        }
        return ans;
    }
};