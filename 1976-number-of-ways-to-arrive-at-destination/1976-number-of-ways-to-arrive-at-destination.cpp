class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> graph(n);
        
        for (auto& road : roads) {
            int start = road[0], end = road[1], cost = road[2];
            graph[start].push_back({end, cost});
            graph[end].push_back({start, cost});
        } 
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;
        vector<long long> shortestTime(n, LLONG_MAX);
        vector<int> pathCount(n,0);

        shortestTime[0] = 0;
        pathCount[0] = 1;
        minHeap.emplace(0,0);

        while (!minHeap.empty()) {
            long long currTime = minHeap.top().first;
            int currNode = minHeap.top().second;
            minHeap.pop();

            if (currTime > shortestTime[currNode]) continue;
            for(auto& [neighbor, cost] : graph[currNode]) {
                if (currTime + cost < shortestTime[neighbor]) {
                    shortestTime[neighbor] = currTime + cost;
                    pathCount[neighbor] = pathCount[currNode];
                    minHeap.emplace(shortestTime[neighbor], neighbor);
                }
                else if (currTime + cost == shortestTime[neighbor]) {
                    pathCount[neighbor] = (pathCount[neighbor] + pathCount[currNode]) % MOD;
                }
            }
        } 
        return pathCount[n-1];
    }
};