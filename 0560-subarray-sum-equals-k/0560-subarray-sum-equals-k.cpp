class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        for (int start = 0; start < nums.size(); start++) {
            int midSum = 0;
            for (int end = start; end < nums.size(); end++) {
                midSum += nums[end];
                if (midSum == k) ans++;
            } 
        }
        return ans; 
    }
};