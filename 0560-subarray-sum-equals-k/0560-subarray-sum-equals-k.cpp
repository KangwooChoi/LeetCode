class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> umap;
        umap.insert({0,1});
        int midSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            midSum += nums[i];
            umap[midSum]++;
            int key = midSum - k;
            if (umap.find(key) != umap.end()) {
                ans += umap[key];
            }
        }
        return ans;
    }
};
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int ans = 0;
//        for (int start = 0; start < nums.size(); start++) {
//            int midSum = 0;
//            for (int end = start; end < nums.size(); end++) {
//                midSum += nums[end];
//                if (midSum == k) ans++;
//            } 
//        }
//        return ans; 
//    }
//};