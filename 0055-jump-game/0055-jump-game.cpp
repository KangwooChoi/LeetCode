class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[n-1] = true;
        for (int i = n - 2; i >= 0; i--) {
            int farJump = min(i + nums[i], (int)nums.size()-1);
            for (int j = i + 1; j <= farJump; j++) {
                if (dp[j] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0]; 
    }
};