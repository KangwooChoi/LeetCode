class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0; 
        int n = nums.size();
        for (int left = 0; left < n; left++) {
            int numZeroes = 0;
            for (int right = left; right < n; right++) {
                if (nums[right] == 0) {
                    numZeroes += 1;
                }
                if (numZeroes <= 1) {
                    result = max(result, right-left+1);
                }
            }
        }
        return result;
    }
};