class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans = 1;
        sort(nums.begin(), nums.end());
        int premin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - premin > k) {
                premin = nums[i];
                ans++;
            }
        } 
        return ans;
    }
};