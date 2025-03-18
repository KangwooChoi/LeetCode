class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int usedBits = 0;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            while ((usedBits & nums[right]) != 0) {
                usedBits ^= nums[left];
                left++;
            }
            usedBits |= nums[right];
            ans = max(ans, right - left + 1);
        } 
        return ans;
    }
};