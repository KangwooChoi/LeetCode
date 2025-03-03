class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        umap[0] = 1;
        int ans = 0;
        int sum = 0;
        for (auto num : nums) {
            sum += num;
            if (umap.find(sum-k) != umap.end()) {
                ans += umap[sum-k];
            }
            umap[sum]++;
        }
        return ans;
    }
};
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