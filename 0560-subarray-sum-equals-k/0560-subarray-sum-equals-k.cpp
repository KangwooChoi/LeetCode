class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> seen;
        seen[0] = 1;
        int sum = 0;
        int ans = 0;
        for (auto num : nums) {
            sum += num;
            if (seen.find(sum-k) != seen.end()) {
                ans += seen[sum-k];
            }
            seen[sum]++;
        }
        return ans;
    }
};
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<vector<int>> dp(n, vector<int>(n));
//        for (int start = 0; start < n; start++) {
//            int sum = 0;
//            for (int end = start; end < n; end++) {
//                sum += nums[end];
//                dp[start][end] = sum; 
//            }
//        }
//        int ans = 0;
//        for (int start = 0; start < n; start++) {
//            for (int end = start; end < n; end++) {
//                if (dp[start][end] == k) ans++;
//            }
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        unordered_map<int,int> umap;
//        umap[0] = 1;
//        int ans = 0;
//        int sum = 0;
//        for (auto num : nums) {
//            sum += num;
//            if (umap.find(sum-k) != umap.end()) {
//                ans += umap[sum-k];
//            }
//            umap[sum]++;
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<int> partSum(n+1, 0);
//        for (int i = 0; i < n; i++) {
//            partSum[i+1] = partSum[i] + nums[i];
//        } 
//        int left = 0;
//        int ans = 0;
//        for (int left = 0; left < n + 1; left++) {
//            for (int right = left + 1; right < n+1; right++) {
//                if (partSum[right] - partSum[left] == k) ans++;
//            }
//        }
//        return ans;
//    }
//};