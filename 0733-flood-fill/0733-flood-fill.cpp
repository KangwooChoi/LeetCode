class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        queue<pair<int,int>> q;
        if (image[sr][sc] == color) return image;
        int prevColor = image[sr][sc];
        q.push({sr,sc}); 
        image[sr][sc] = color;
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = row + dx[k];
                    int ny = col + dy[k];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && image[nx][ny] == prevColor) {
                        q.push({nx,ny});
                        image[nx][ny] = color;
                    }
                }
            }
        }
        return image;
    }
};