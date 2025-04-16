class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int same = 0, right = -1;
        unordered_map<int,int> freq;
        long long ans = 0;
        for (int left = 0; left < n; left++) {
            while (same < k && right + 1 < n) {
                ++right;
                same += freq[nums[right]];
                ++freq[nums[right]];
            }
            if (same >= k) {
                ans += n - right;
            }
            --freq[nums[left]];
            same -= freq[nums[left]];
        }
        return ans;
    }
};
//class Solution {
//public:
//    long long countGood(vector<int>& nums, int k) {
//        unordered_map<int,int> freq;
//        int n = nums.size();
//        long long ans = 0;
//        int pairCnt = 0;
//        int left = 0;
//        for (int right = 0; right < nums.size(); right++) {
//            if (++freq[nums[right]] == 2) pairCnt++;
//            if (pairCnt == k) {
//                ans += n - right; 
//                while (pairCnt == k && left <= right) {
//                    if(freq[nums[left++]]-- == 2) pairCnt--;
//                }
//            }
//        }
//        return ans;
//    }
//};