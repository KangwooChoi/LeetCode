class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        for (auto num : nums) {
            pq.push((long)num);
        }
        int ans = 0;
        while (pq.top() < (long)k) {
            ans++;
            long n1 = pq.top();
            pq.pop();
            long n2 = pq.top();
            pq.pop();
            long n3 = min(n1,n2)*2+max(n1,n2);
            pq.push(n3);
        }
        return ans;    
    }
};