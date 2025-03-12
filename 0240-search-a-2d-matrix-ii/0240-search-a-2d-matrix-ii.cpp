class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        int col = 0;
        while (0 <= row && col < matrix[0].size()) {
            if (matrix[row][col] > target) {
                row--;
            } else if (matrix[row][col] < target) {
                col++; 
            } else {
                return true;
            }
        }
        return false;
    }
};
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        for (int row = 0; row < matrix.size(); row++) {
//            if (matrix[row][0] > target) break;
//            for (int col = 0; col < matrix[0].size(); col++) {
//                if (matrix[row][col] == target) return true;
//                if (matrix[row][col] > target) break;
//            }
//        }
//        return false;
//    }
//};