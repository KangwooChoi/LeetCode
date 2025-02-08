class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int ans = 0;
        int midsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (midsum + nums[i] < 0) ans++;
            else midsum += nums[i];
        }
        return ans; 
    }
};