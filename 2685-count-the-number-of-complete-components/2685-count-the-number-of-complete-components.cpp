class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UnionFind dsu(n);
        unordered_map<int,int> edgeCount;
        for (const auto& edge: edges) {
            dsu.unionSets(edge[0], edge[1]);
        }
        for (const auto& edge : edges) {
            int root = dsu.find(edge[0]);
            edgeCount[root]++;
        }
        int ans = 0;
        for (int vertex = 0; vertex < n; vertex++) {
            if (dsu.find(vertex) == vertex) {
                int nodeCount = dsu.size[vertex];
                int expectedEdges = (nodeCount*(nodeCount-1)) / 2;
                if (edgeCount[vertex] == expectedEdges) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> size;
        UnionFind(int n) : parent(n, -1), size(n, 1) {}
        int find(int node) { 
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }
        void unionSets(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);
            if (root1 == root2) {
                return;
            }
            if (size[root1] > size[root2]) {
                parent[root2] = root1;
                size[root1] += size[root2];
            } else {
                parent[root1] = root2;
                size[root2] += size[root1];
            }
        }
    };
};
//class Solution {
//public:
//    int countCompleteComponents(int n, vector<vector<int>>& edges) {
//        vector<vector<bool>> dp(n, vector<bool>(n,false)); 
//        int ans = 0;
//        vector<int> parent(n);
//        for (int i = 0; i < n; i++) {
//            parent[i] = i;
//        }
//        for (auto edge : edges) {
//            int s = edge[0], e = edge[1];
//            dp[s][e] = true;
//            dp[e][s] = true;
//        }
//        for (int i = 0; i < n - 1; i++) {
//            for (int j = i + 1; j < n; j++) {
//                if(dp[i][j] && i < parent[j]) parent[j] = i;    
//            }
//        }
//        vector<vector<int>> groups(n);
//        for (int i = 0; i < n; i++) {
//            groups[parent[i]].push_back(i);
//        }
//        for (auto group : groups) {
//            int size = group.size();
//            if (size == 0) continue;
//            if (size <= 2) {
//                ans++;
//                continue;
//            }
//            bool isComplete = true;
//            for (int i = 0; i < size; i++) {
//                for (int j = 0; j < size; j++) {
//                    if (i == j) continue;
//                    int s = group[i], e = group[j];
//                    if (dp[s][e] != true) {
//                        isComplete = false;
//                        break;
//                    }
//                }
//            }
//            if (isComplete) ans++;
//        }
//        return ans;
//    }
//};