class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashing;
        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i]; 
            if (hashing.find(comp) != hashing.end()) {
                return {i, hashing[comp]};
            } else {
                hashing[nums[i]] = i;
            }
        }
        return {}; 
    }
};