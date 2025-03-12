class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][0] > target) break;
            for (int col = 0; col < matrix[0].size(); col++) {
                if (matrix[row][col] == target) return true;
                if (matrix[row][col] > target) break;
            }
        }
        return false;
    }
};