class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int ans = 0;
        int k_new = 2 * k;
        for (int right = 0; right < nums.size(); right ++) {
            if (nums[right] - nums[left] <= k_new) {
                ans = max(ans, right - left + 1);
            } else {
                while (left < right) {
                    left++;
                    if (nums[right] - nums[left] <= k_new) {
                        ans = max(ans, right - left + 1);
                        break;
                    }
                }
            }

        }
        return ans; 
    }
};