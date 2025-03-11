class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                dfs(isConnected, visited, i);
            } 
        }
        return ans; 
    }
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        if (visited[i]) return;
        visited[i] = true;
        int n = isConnected.size();
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1) {
                dfs(isConnected, visited, j);
            }
        } 
    }
};