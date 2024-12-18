class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        stack<int> stack;

        for (int i = 0; i < prices.size(); i++) {
            while (!stack.empty() && prices[stack.top()] >= prices[i]) {
                ans[stack.top()] -= prices[i];
                stack.pop();
            }
            stack.push(i);
        }
        return ans;
    }
};
//class Solution {
//public:
//    vector<int> finalPrices(vector<int>& prices) {
//        int n = prices.size();
//        vector<int> answer = prices;
//        for (int i = 0; i < n; i++) {
//            for (int j = i+1; j < n; j++) {
//                if (prices[i] >= prices[j]) {
//                    answer[i] = prices[i] - prices[j];
//                    break;
//                }
//            }
//        }
//        return answer;        
//    }
//};