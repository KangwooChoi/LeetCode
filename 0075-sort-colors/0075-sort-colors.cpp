class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int right = n - 1; 
        for (int i = 0; i < n; i++) {
            if (nums[i] == 2) {
                while (nums[right] == 2 && i < right) {
                    right--;
                }
                swap(nums[i], nums[right]);
            }
        }
        for (int i = 0; i < right; i++) {
            if (nums[i] == 1) {
                while (nums[right] >= 1 && i < right) {
                    right--;
                }
                swap(nums[i], nums[right]);
            }
        }
    }
};