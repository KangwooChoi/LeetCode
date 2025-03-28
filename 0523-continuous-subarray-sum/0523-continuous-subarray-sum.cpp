class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixMod = 0;
        unordered_map<int,int> modSeen;
        modSeen[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            prefixMod = (prefixMod + nums[i]) % k;
            if (modSeen.find(prefixMod) != modSeen.end()) {
                if (i - modSeen[prefixMod] > 1) {
                    return true;
                }
            } else {
                modSeen[prefixMod] = i;
            }
        }
        return false;
    }
};
//class Solution {
//public:
//    bool checkSubarraySum(vector<int>& nums, int k) {
//        for (int i = 0; i < nums.size(); i++) {
//            int partSum = nums[i];
//            for (int j = i+1; j < nums.size(); j++) {
//                partSum += nums[j];
//                if (partSum % k == 0) return true;
//            }
//        }
//        return false; 
//    }
//};