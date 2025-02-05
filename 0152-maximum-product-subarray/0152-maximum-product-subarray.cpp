class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int mid = nums[i];
            ans = max(ans, mid);
            for (int j = i + 1; j < n; j++) {
                mid *= nums[j];
                ans = max(ans, mid);
                if (nums[j] == 0) break;
            }
        }
        return ans; 
    }
};