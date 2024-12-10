class Solution {
public:
    typedef long long ll;
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int head = 0;
        int n = costs.size();
        int tail = n - 1;
        ll ans = 0;
        int count = 0;
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        while (count < k) {
            while(pq1.size() < candidates && head <= tail) pq1.push(costs[head++]);
            while(pq2.size() < candidates && tail >= head) pq2.push(costs[tail--]);

            int h = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int t = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (h <= t) {
                ans += h;
                pq1.pop();
            } else {
                ans += t;
                pq2.pop();
            }
            count++;
        }
        return ans;
    }
};