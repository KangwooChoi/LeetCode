class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        umap[0] = -1;
        int sum = 0;
        int left = -1, right = -1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (umap.find(sum-k) != umap.end()) {
                left = umap[sum-k], right = i;
                ans = max(ans, right - left);
            }
            if (umap.find(sum) == umap.end()) umap[sum] = i;
        }       
        return ans;
    }
};