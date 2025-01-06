class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n,0);
        
        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;
        
        for (int i = 0; i < n; i++) {
            ans[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            int j = n - 1 - i;
            ans[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;

        }
        return ans;
    }
};
//class Solution {
//public:
//    vector<int> minOperations(string boxes) {
//        int n = boxes.length();
//        vector<int> ans(n, 0); 
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                if (boxes[j] == '1') {
//                    //ans[i] += (j > i) ? j - i : i - j;
//                    ans[i] += abs(j-i);
//                }
//            }
//        }
//        return ans;
//    }
//};