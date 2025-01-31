class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSub = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currSub = max(nums[i], currSub + nums[i]);
            ans = max(ans, currSub);
        }
        return ans;
    }
};
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int ans = INT_MIN;
//        int n = nums.size();
//        vector<int> sumLeft(n+1, 0);
//        for (int i = 0; i < n; i++) {
//            sumLeft[i+1] = sumLeft[i] + nums[i];
//        }
//        for (int i = 0; i < n+1; i++) {
//            for (int j = i + 1; j < n+1; j++) {
//                ans = max(ans, sumLeft[j] - sumLeft[i]);
//            }
//        }
//        return ans;
//    }
//};