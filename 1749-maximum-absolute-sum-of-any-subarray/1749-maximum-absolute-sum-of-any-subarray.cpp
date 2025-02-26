class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0, prefixSum = 0;
        int minPrefixSum = INT_MAX, maxPrefixSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            minPrefixSum = min(prefixSum, minPrefixSum);
            maxPrefixSum = max(prefixSum, maxPrefixSum);
            if (prefixSum >= 0) {
                ans = max(ans, max(prefixSum, prefixSum - minPrefixSum)); 
            } else {
                ans = max(ans, max(abs(prefixSum), abs(maxPrefixSum - prefixSum))); 
            }
        }
        return ans;
    }
};
//class Solution {
//public:
//    int maxAbsoluteSum(vector<int>& nums) {
//        int n = nums.size();
//        int ans = 0;
//        for (int i = 0; i < n; i++) {
//            int prev = nums[i];
//            ans = max(ans, abs(prev));
//            for (int j = i+1; j < n; j++) {
//                int curr = prev + nums[j];
//                ans = max(ans, abs(curr));
//                prev = curr;
//            }   
//        }
//        return ans;
//    }
//};