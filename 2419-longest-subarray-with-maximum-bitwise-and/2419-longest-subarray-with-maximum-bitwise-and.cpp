class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_num = 0;
        for (int num : nums) {
            if (num > max_num) max_num = num;
        } 
        int ans = 0;
        for (int right = 0; right < nums.size();) {
            int cnt = 0;
            while (right < nums.size() && nums[right++] == max_num) cnt++; 
            ans = max(cnt, ans);
        }
        return ans;
    }
};