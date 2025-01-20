class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int ans = -1;
        vector<vector<int>> hash(m*n+1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                hash[mat[i][j]].push_back(i);
                hash[mat[i][j]].push_back(j);
            }
        }
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int k = 0; k < arr.size(); k++) {
            int r = hash[arr[k]][0];
            int c = hash[arr[k]][1];
            row[r]++;
            if (row[r] == n) return k;
            col[c]++;
            if (col[c] == m) return k;
        }

        return ans; 
    }
};