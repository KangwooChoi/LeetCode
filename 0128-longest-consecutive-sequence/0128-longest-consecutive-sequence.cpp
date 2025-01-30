class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        priority_queue<int> pq;
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        } 
        int curr = pq.top();
        int intermediate = 1;
        pq.pop();
        while (!pq.empty()) {
            if (curr == pq.top()) {
                pq.pop();
                continue;
            };
            if (curr-1 == pq.top()) {
                intermediate++;
                ans = max(ans, intermediate);
            } else {
                intermediate = 1;
            } 
            curr = pq.top();
            pq.pop();
        }
        return ans;
    }
};