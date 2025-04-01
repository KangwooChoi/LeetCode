class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            int point = questions[i][0];
            int jump = questions[i][1];

            int nextQuestion = min(n, i+jump+1);
            dp[i] = max(dp[i+1], point+dp[nextQuestion]);
        }
        return dp[0];
    }
};
//class Solution {
//public:
//    long long ans;
//
//    long long mostPoints(vector<vector<int>>& questions) {
//        long long res = 0;
//        backtrack(questions, 0, res); 
//        return ans;
//    }
//private:
//    void backtrack(vector<vector<int>>& questions, int index, long long res) {
//        if (questions.size() <= index) {
//            ans = max(ans, res);
//            return;
//        } 
//        auto q = questions[index];
//        int point = q[0], next = q[1];
//        backtrack(questions, index+next+1, res+(long)point);
//        backtrack(questions, index+1, res); 
//        return;
//    }
//};