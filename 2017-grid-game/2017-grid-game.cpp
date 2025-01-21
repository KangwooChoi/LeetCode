class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL),
                  secondRowSum = 0;
        long long minimumSum = LONG_LONG_MAX;
        for (int turnIndex = 0; turnIndex < grid[0].size(); ++turnIndex) {
            firstRowSum -= grid[0][turnIndex];
            // Find the minimum maximum value out of firstRowSum and
            // secondRowSum.
            minimumSum = min(minimumSum, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][turnIndex];
        }
        return minimumSum;
    }
};
//class Solution {
//public:
//    long long gridGame(vector<vector<int>>& grid) {
//        int n = grid[0].size();
//        vector<long long> left(n,0);    
//        vector<long long> right(n,0);    
//        left[0] = grid[0][0];
//        for (int i = 1; i < n; i++) {
//            left[i] = left[i-1] + grid[0][i]; 
//        }
//        right[n-1] = grid[1][n-1];
//        for (int j = n - 2; j >= 0; j--) {
//            right[j] = right[j+1] + grid[1][j];
//        }
//        int index = 0;
//        long long maximum = 0;
//        long long temp = 0;
//        for (int k = 0; k < n; k++) {
//            temp = left[k] + right[k];
//            if (temp > maximum) {
//                index = k;
//                maximum = temp;
//            }
//        }
//        for (int l = 0; l <= index; l++) grid[0][l] = 0;
//        for (int l = index; l < n; l++) grid[1][l] = 0;
//
//        vector<long long> left2(n,0);    
//        vector<long long> right2(n,0);    
//        left2[0] = grid[0][0];
//        for (int i = 1; i < n; i++) {
//            left2[i] = left2[i-1] + grid[0][i]; 
//        }
//        right2[n-1] = grid[1][n-1];
//        for (int j = n - 2; j >= 0; j--) {
//            right2[j] = right2[j+1] + grid[1][j];
//        }
//        int index2 = 0;
//        long long maximum2 = 0;
//        for (int k = 0; k < n; k++) {
//            long long temp2 = left2[k] + right2[k];
//            if (temp2 > maximum2) {
//                index2 = k;
//                maximum2 = temp2;
//            }
//        }
//        return left2[index2] + right2[index2];
//    }
//};