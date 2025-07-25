class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> seen;
        int neg_max = -101;
        int ans = 0;
        for (int num : nums) {
            if (num < 0) {
                if (neg_max < num) neg_max = num;
            } else {
                if (seen.count(num)) {
                    continue;
                } else {
                    ans += num;
                    seen.insert(num);
                }
            }
        } 
        return seen.empty() ? neg_max : ans; 
    }
};