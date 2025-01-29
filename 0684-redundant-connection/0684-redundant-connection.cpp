class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent;
        for (int i = 0; i < n+1; i++) {
            parent.push_back(i);
        }
        vector<int> ans;
        for (auto edge : edges) {
            int s = edge[0];
            int e = edge[1];
            if (find(parent, s) == find(parent, e)) return edge;
            merge(parent, s, e);
        }
        return ans;
    }
private:
    int find(vector<int>& parent, int a) {
        if (parent[a] == a) return parent[a];
        parent[a] = find(parent, parent[a]);
        return parent[a]; 
    }
    void merge(vector<int>& parent, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);
        if (a != b) parent[b] = a;
    }
};