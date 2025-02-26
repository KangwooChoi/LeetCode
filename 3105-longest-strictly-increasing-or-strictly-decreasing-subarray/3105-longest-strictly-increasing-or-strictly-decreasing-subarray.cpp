class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1;
        int incMax = 1, decMax = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i-1] < nums[i]) {
                incMax = max(incMax, ++inc);
                dec = 1;
            }
            else if (nums[i-1] > nums[i]) {
                decMax = max(decMax, ++dec);
                inc = 1;
            } else {
                dec = 1;
                inc = 1;
            }

        }
        return max(incMax, decMax); 
    }
};