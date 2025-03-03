class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (minprice > prices[i]) {
                minprice = prices[i];
            } else {
                maxprofit = max(maxprofit, prices[i] - minprice);
            }
        }
        return maxprofit;
    }
};
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int minprice = INT_MAX;
//        int maxprofit = 0;
//        for (int i = 0; i < prices.size(); i++) {
//            if (minprice > prices[i]) {
//                minprice = prices[i];
//            } else if (prices[i] - minprice > maxprofit) {
//                maxprofit = prices[i] - minprice;
//            } 
//        }
//        return maxprofit;
//    }
//};
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        vector<int> left(n, 10001);
//        vector<int> right(n, 0);
//        left[0] = prices[0];
//        right[n-1] = prices[n-1];
//        for (int i = 1; i < n; i++) {
//            left[i] = min(left[i-1], prices[i]);
//        }
//        for (int i = n-2; i >= 0; i--) {
//            right[i] = max(right[i+1], prices[i]);
//        }
//        int ans = 0;
//        for (int i = 0; i < n; i++) {
//            ans = max(ans, right[i] - left[i]);
//        } 
//        return ans;
//    }
//};