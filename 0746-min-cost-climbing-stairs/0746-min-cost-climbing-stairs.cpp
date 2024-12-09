class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minimum_cost(n + 1, 0);
        for (int i = 2; i < n + 1; i++) {
            int onestep_cost = minimum_cost[i - 1] + cost[i - 1];
            int twostep_cost = minimum_cost[i - 2] + cost[i - 2];
            minimum_cost[i] = min(onestep_cost, twostep_cost);
        }
        return minimum_cost[n]; 
    }
};