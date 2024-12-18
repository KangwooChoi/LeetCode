class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer = prices;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (prices[i] >= prices[j]) {
                    answer[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return answer;        
    }
};