class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (!helper(matrix, i, 0)) return false;
        }  
        for (int j = 1; j < n; j++) {
            if (!helper(matrix, 0, j)) return false;
        }
        return true;
    }
private:
    bool helper(const vector<vector<int>>& matrix, int row, int col) {
        int m = matrix.size(), n = matrix[0].size();
        int val = matrix[row++][col++];
        while (row < m && col < n) {
            if (val != matrix[row++][col++]) return false;
        }
        return true;
    }
};