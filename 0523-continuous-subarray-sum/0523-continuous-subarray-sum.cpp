class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map<int,int> seen;
        seen[0] = -1;    
        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % k;
            if (seen.find(prefix) != seen.end()) {
                if (i - seen[prefix] > 1) return true;
            } else {
                seen[prefix] = i;
            }
        }
        return false;
    }
};