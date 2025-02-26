class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> umap;
        for (int i = 0; i < n; i++) {
            umap[nums[i]]++;
        }
        for (auto [num, freq] : umap) {
            if (freq > n / 2) return num;
        }
        return -1; 
    }
};