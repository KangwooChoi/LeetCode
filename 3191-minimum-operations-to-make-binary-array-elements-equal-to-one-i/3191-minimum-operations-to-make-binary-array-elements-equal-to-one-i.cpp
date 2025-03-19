class Solution {
public:
    int minOperations(vector<int>& nums) {
        // greedy
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 0) {
                flip(nums, i);
                ans++;
            }
        } 
        if (nums[n-2] == 0 || nums[n-1] == 0) {
            return -1;
        }
        return ans;
    }
     
private:
    void flip(vector<int>& nums, int index) {
        nums[index++] ^= 1;
        nums[index++] ^= 1;
        nums[index] ^= 1;
    }
};