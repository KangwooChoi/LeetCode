class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 2; i < n; i++) {
            int left = 0, mid = i - 1;
            while (left < mid) {
                if (nums[left] + nums[mid] > nums[i]) {
                    ans += mid - left;
                    mid--;
                }
                else left++;
            }
        }
        return ans;
    }
};