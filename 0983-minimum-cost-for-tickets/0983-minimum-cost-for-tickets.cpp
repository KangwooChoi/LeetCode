class Solution {
public:
int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, 0);
    
        int i = 0;
        for (int day = 1; day <= lastDay; day++) {
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                i++;
                dp[day] = min({dp[day - 1] + costs[0],
                               dp[max(0, day - 7)] + costs[1],
                               dp[max(0, day - 30)] + costs[2]});
            }
        }
        return dp[lastDay];
    }
};
//class Solution {
//public:
//    int mincostTickets(vector<int>& days, vector<int>& costs) {
//        stack<int> s;
//        for (int i = days.size() - 1; i >= 0; i--) {
//            s.push(days[i]);
//        }
//        return mincost(s, costs, 0, 0); 
//    }
//private:
//    int mincost(stack<int> s, vector<int>& costs, int curr_day, int curr_cost) {
//        while (!s.empty()) {
//            if (s.top() > curr_day) break;
//            s.pop();
//        }
//        if (s.empty()) return curr_cost;
//        int now = s.top();
//        return min({mincost(s, costs, now, curr_cost + costs[0]),
//                    mincost(s, costs, now+6, curr_cost + costs[1]),
//                    mincost(s, costs, now+29, curr_cost + costs[2])});
//    }
//};