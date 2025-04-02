class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n,0); 
        vector<int> rightMax(n,0); 
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], nums[i-1]);
            rightMax[n-1-i] = max(rightMax[n-i], nums[n-i]);
        }
        long long res = 0;
        for (int i = 1; i < n-1; i++) {
            res = max(res, (long long)(leftMax[i]-nums[i])*rightMax[i]);
        }
        return res;
    }
};
//class Solution {
//public:
//    long long maximumTripletValue(vector<int>& nums) {
//        long long ans = 0;
//        int n = nums.size();
//        for (int i = 0; i < n-2; i++) {
//            for (int j = i+1; j < n-1; j++) {
//                for (int k = j+1; k < n; k++) {
//                    if (nums[i] <= nums[j]) continue;
//                    long long temp = ((long)nums[i]-(long)nums[j]) * nums[k];
//                    ans = max(ans, temp);
//                }
//            }
//        }
//        return ans; 
//    }
//};