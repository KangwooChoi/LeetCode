class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for (int i = 0; i <= k && i < nums.size(); i++) {
            if (++umap[nums[i]] >= 2) return true;
        }
        for (int i = k+1; i < nums.size(); i++) {
            umap[nums[i-k-1]]--; 
            if (++umap[nums[i]] >= 2) return true;
        }
        return false; 
    }
};