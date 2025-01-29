class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n-1 > edges.size()) return false;
        vector<int> parent(n,0);
        for (int i = 1; i < n; i++) {
            parent[i] = i; 
        } 
        for (auto edge : edges) {
            int s = edge[0];
            int e = edge[1];
            if (find(parent,s) == find(parent,e)) return false;
            merge(parent, s, e);
        }
        return true; 
    }
private:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) return parent[x];
        return find(parent, parent[x]);
    }
    bool merge(vector<int>& parent, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);
        if (a!=b) {
            parent[b] = a;
            return true;
        }
        return false; 
    }
};