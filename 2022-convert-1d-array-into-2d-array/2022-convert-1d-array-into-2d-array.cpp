class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if (original.size() != m * n) return ans;
        for (int i = 0; i < m; ++i) {
            ans.push_back(vector<int>(original.begin()+i*n, original.begin()+(i+1)*n));
        }
        return ans;
    }
};