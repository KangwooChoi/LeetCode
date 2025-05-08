class State {
public: 
    int x;
    int y;
    int dist;
    State(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

class Solution {
public:
    const int INF = INT_MAX;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INF));
        vector<vector<bool>> visited(n, vector<bool>(m,false));

        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        dp[0][0] = 0;

        auto cmp = [](const State& a, const State& b) {return a.dist > b.dist;};
        priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
        pq.push(State(0,0,0));

        while(!pq.empty()) {
            State s = pq.top();
            pq.pop();
            if (visited[s.x][s.y]) continue;
            if (s.x == n - 1 && s.y == m - 1) break;
        
            visited[s.x][s.y] = true;
            for (int k = 0; k < 4; k++) {
                int nx = s.x + dir[k][0];
                int ny = s.y + dir[k][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int ndist = max(dp[s.x][s.y], moveTime[nx][ny]) + (s.x + s.y)  % 2 + 1;
                if (dp[nx][ny] > ndist) {
                    dp[nx][ny] = ndist;
                    pq.push(State(nx, ny, ndist));
                }
            }
        }

        return dp[n-1][m-1];
    }
};