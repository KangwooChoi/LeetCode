class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1;
        int max_inc = 1, max_dec = 1;
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i-1] < nums[i]) {
                max_inc = max(max_inc, ++inc);
                dec = 1;
            } else if (nums[i-1] > nums[i]) {
                inc = 1;
                max_dec = max(max_dec, ++dec);
            } else {
                inc = 1; 
                dec = 1;
            }
        }
        return max(max_inc, max_dec); 
    }
};