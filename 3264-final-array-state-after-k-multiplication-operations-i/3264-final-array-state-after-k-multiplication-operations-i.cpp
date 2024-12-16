class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({-nums[i], -i});
        }
        pair<int, int> curr;
        int val = 0, index = 0;
        while(k > 0) {
            curr = pq.top();
            val = -curr.first;
            index = -curr.second;
            nums[index] = val * multiplier;
            pq.pop();
            pq.push({-val*multiplier, -index});
            k--;
        }
        return nums; 
    }
};