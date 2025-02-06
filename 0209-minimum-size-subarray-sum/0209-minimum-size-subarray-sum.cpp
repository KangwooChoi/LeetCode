class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, window = 0;
        int ans = INT_MAX; 
        for (int right = 0; right < nums.size(); right++) {
            window += nums[right];
            while (window >= target) {
                ans = min(ans, right - left + 1);
                window -= nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};