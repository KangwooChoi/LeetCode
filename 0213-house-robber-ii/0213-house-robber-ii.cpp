class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int max1 = helper(nums, 0, nums.size()-2);
        int max2 = helper(nums, 1, nums.size()-1);
        return max(max1,max2);
    }
private:
    int helper(vector<int>& nums, int start, int end) {
        int t1 = 0, t2 = 0;
        for (int i = start; i <= end; i++) {
            int temp = t1;
            t1 = max(nums[i] + t2, t1);
            t2 = temp;
        }
        return t1;
    }
};
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 1) return nums[0];
//        if (n == 2) return max(nums[0], nums[1]); 
//        vector<int> dp(n,0);
//        dp[0] = nums[0];
//        dp[1] = max(nums[0], nums[1]);
//        for (int i = 2; i < n; i++) {
//            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
//        }
//        return dp[n-1];
//    }
//};