class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        int acc = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > acc) {
                acc = nums[i];
                ans++;
            }
        } 
        return ans;
    }
};