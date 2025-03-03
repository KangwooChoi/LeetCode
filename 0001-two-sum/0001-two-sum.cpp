class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (umap.find(complement) != umap.end()) {
                return {umap[complement], i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        int n = nums.size();
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                if (nums[i] + nums[j] == target) return {i,j};
//            }
//        }
//        return {}; 
//    }
//};