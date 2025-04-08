class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n); 
        for (int i = 0; i < n; i++) parents[i] = i;
        vector<vector<int>> graph;
        for (auto edge : edges) {
            int s = edge[0], e = edge[1];
            add(s, e, parents);
        }
        unordered_map<int,int> freq;
        for (int i = 0; i < n; i++) {
            parents[i] = find(i, parents);
            freq[parents[i]]++;
        }
        int ans = 0;
        for (auto [key, val] : freq) {
            if (val >= 1) ans++;
        }
        return ans;
    }
private:
    int find(int child, vector<int>& parents) {
        if (child == parents[child]) return parents[child];
        parents[child] = find(parents[child], parents);
        return parents[child];
    }
    void add(int s, int e, vector<int>& parents) {
        s = find(s, parents);
        e = find(e, parents);
        if (s < e) {
            parents[e] = s;
        } else {
            parents[s] = e;
        }
    }
};