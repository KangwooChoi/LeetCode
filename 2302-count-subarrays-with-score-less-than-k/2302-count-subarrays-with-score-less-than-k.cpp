class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0, total = 0;
        for (int i = 0, j = 0; j < n; j++) {
            total += nums[j];
            while (i <= j && total * (j - i + 1) >= k) {
                total -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};
//class Solution {
//public:
//    long long countSubarrays(vector<int>& nums, long long k) {
//        int n = nums.size();
//        vector<int> cheatingSheet(n,1);     
//        for (int i = 1; i < n; i++) {
//            cheatingSheet[i] = cheatingSheet[i-1] + i + 1;
//        }
//        int ans = 0;
//        for (int left = 0; left < n; left++) {
//            int part = 0;
//            for (int right = left; right < n; right++) {
//                part += nums[right];
//                if (part * (right - left + 1) > k) {
//                    if (right > left) {
//                        ans += cheatingSheet[right-left-1];
//                    } 
//                    break;
//                }
//            }
//        }
//        return ans;
//    }
//};