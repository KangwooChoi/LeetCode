class State {
public:
    int x;
    int y;
    int dis;
    State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int inf = 0x3f3f3f3f;
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, inf));
        vector<vector<int>> v(n, vector<int>(m, 0));

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        d[0][0] = 0;

        auto cmp = [](const State& a, const State& b) { return a.dis > b.dis; };

        priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
        q.push(State(0, 0, 0));

        while (!q.empty()) {
            State s = q.top();
            q.pop();
            if (v[s.x][s.y]) continue;
            v[s.x][s.y] = 1;

            for (int i = 0; i < 4; i++) {
                int nx = s.x + dirs[i][0];
                int ny = s.y + dirs[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1;
                if (d[nx][ny] > dist) {
                    d[nx][ny] = dist;
                    q.push(State(nx, ny, dist));
                }
            }
        }

        return d[n - 1][m - 1];
    }
};
//class Solution {
//public:
//    int minTimeToReach(vector<vector<int>>& moveTime) {
//        vector<vector<int>> dir = {{1,0}, {0,-1}, {-1,0}, {0,1}};
//        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
//        int n = moveTime.size();
//        int m = moveTime[0].size();
//        vector<vector<bool>> visited(n, vector<bool>(m, false));
//        pq.push({0, 0, 0});
//        while (!pq.empty()) {
//            int cost = pq.top()[0];
//            int x = pq.top()[1];
//            int y = pq.top()[2];
//            visited[x][y] = true;
//            pq.pop();
//            if (x == moveTime.size() - 1 && y == moveTime[0].size() - 1) return cost;
//            for (int k = 0; k < 4; k++) {
//                int nx = x + dir[k][0];
//                int ny = y + dir[k][1];
//                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
//                    if (visited[nx][ny]) continue;
//                    int ncost = max(cost+1, moveTime[nx][ny]+1);
//                    pq.push({ncost,nx,ny});
//                }
//            }
//        }
//        return -1;    
//    }
//};