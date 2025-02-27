class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        queue<pair<int,int>> q; 
        int origin = image[sr][sc];
        image[sr][sc] = color;
        q.push({sr,sc});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = curr.first + dx[k]; 
                    int ny = curr.second + dy[k]; 
                    if (0 <= nx && nx < image.size() && 0 <= ny && ny < image[0].size()) {
                        if (image[nx][ny] == origin) {
                            image[nx][ny] = color;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        } 
        return image;
    }
};