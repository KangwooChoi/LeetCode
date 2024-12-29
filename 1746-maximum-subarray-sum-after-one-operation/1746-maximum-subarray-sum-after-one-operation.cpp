class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxLeft(n);
        vector<int> maxRight(n);

        maxLeft[0] = 0;
        for (int i = 0; i < n; i++) {
            maxLeft[i] = max(maxLeft[i-1] + nums[i-1], 0);
        }

        maxRight[n-1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i+1] + nums[i+1], 0);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, maxLeft[i] + nums[i] * nums[i] + maxRight[i]);
        }
        return ans;
    }
};