class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> connected(m, vector<int>(n,0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            vector<pair<int,int>> servers;
            for (int j = 0; j< n; j++) {
                if (grid[i][j] == 1) {
                    servers.push_back({i,j});
                }
            }
            if (servers.size() >= 2) {
                for (int k = 0; k < servers.size(); k++) {
                    int x = servers[k].first;
                    int y = servers[k].second;
                    if (connected[x][y] == 0) {
                        ans++;
                        connected[x][y] = 1;
                    }
                }

            }
        }
        for (int i = 0; i < n; i++) {
            vector<pair<int,int>> servers;
            for (int j = 0; j < m; j++) {
                if (grid[j][i] == 1) {
                    servers.push_back({j,i});
                }
            }
            if (servers.size() >= 2) {
                for (int k = 0; k < servers.size(); k++) {
                    int x = servers[k].first;
                    int y = servers[k].second;
                    if (connected[x][y] == 0) {
                        ans++;
                        connected[x][y] = 1;
                    }
                }
            }
        }

        return ans;
    }
};