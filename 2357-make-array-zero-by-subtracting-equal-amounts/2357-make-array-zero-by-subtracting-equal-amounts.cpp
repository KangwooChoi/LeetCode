class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        int acc = 0;
        sort(nums.begin(), nums.end());
        int p = 0; 
        while (p < nums.size()) {
            if (nums[p] != acc) {
                acc = nums[p];
                ans++;
            } 
            p++;
        }
        return ans; 
    }
};